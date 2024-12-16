#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 50;

    vector<string> s(n);

    for(auto &i: s) cin >> i;
    int m = s[0].size();
    int x, y;

    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++){
            if(s[i][l]=='@') x=i, y=l;
        }
    }


    array<int, 4> a ={0, 0, -1, 1};
    array<int, 4> b ={-1, 1, 0, 0};
    array<char, 2> v={'[', ']'};
    auto check2=[&](int t, int posx, int posy, auto&& check2)->int{
        array<int, 2> sol, sag;

        if(s[posx][posy]=='[') sol={posx, posy}, sag={posx, posy+1};
        else sol={posx, posy-1}, sag={posx, posy};
        int k=1;

        if(s[sol[0]+a[t]][sol[1]+b[t]]=='#') k=0;
        else if(s[sol[0]+a[t]][sol[1]+b[t]]==']'||s[sol[0]+a[t]][sol[1]+b[t]]=='['){
            k&=check2(t, sol[0]+a[t], sol[1]+b[t], check2);
        }


        if(s[sag[0]+a[t]][sag[1]+b[t]]=='#') k=0;
        else if(s[sag[0]+a[t]][sag[1]+b[t]]==']'||s[sag[0]+a[t]][sag[1]+b[t]]=='['){
            k&=check2(t, sag[0]+a[t], sag[1]+b[t], check2);
        }

        return k;
    };

    auto check3=[&](int t, int posx, int posy,auto&& check3)->int{
        array<int, 2> sol, sag;

        if(s[posx][posy]=='[') sol={posx, posy}, sag={posx, posy+1};
        else if(s[posx][posy]==']') sol={posx, posy-1}, sag={posx, posy};

        int k=1;

        if(s[sol[0]+a[t]][sol[1]+b[t]]=='#') k=0;
        else if(s[sol[0]+a[t]][sol[1]+b[t]]==']'||s[sol[0]+a[t]][sol[1]+b[t]]=='['){
            k&=check3(t, sol[0]+a[t], sol[1]+b[t], check3);
        }


        if(s[sag[0]+a[t]][sag[1]+b[t]]=='#') k=0;
        else if(s[sag[0]+a[t]][sag[1]+b[t]]==']'||s[sag[0]+a[t]][sag[1]+b[t]]=='['){
            k&=check3(t, sag[0]+a[t], sag[1]+b[t], check3);
        }

        swap(s[sol[0]+a[t]][sol[1]+b[t]], s[sol[0]][sol[1]]);
        swap(s[sag[0]+a[t]][sag[1]+b[t]], s[sag[0]][sag[1]]);

        return k;
    };
    auto check=[&](int t, int &x, int &y){
        if(s[x+a[t]][y+b[t]]=='#') return;
        if(s[x+a[t]][y+b[t]]=='.'){
            swap(s[x][y], s[x+a[t]][y+b[t]]);
            x+=a[t]; y+=b[t];
            return;
        } 
        else{
            int posx = x+a[t], posy=y+b[t];
            if(t<2){

                while(s[posx][posy]!='#'&&s[posx][posy]!='.'){
                    posx+=a[t]; posy+=b[t];
                }

                if(s[posx][posy]=='.'){
                    int p=t;
                    while(posx-a[t]!=x||posy-b[t]!=y){
                        s[posx][posy]=v[p%2];
                        posx-=a[t]; posy-=b[t];
                        p++;
                    }

                    s[posx][posy]='@';
                    s[x][y]='.';
                    x+=a[t]; y+=b[t];
                }
            }
            else{
                int p=check2(t, posx, posy, check2);
                if(p){
                    int g=check3(t, posx, posy, check3);
                    swap(s[posx][posy], s[x][y]);
                    x+=a[t]; y+=b[t];
                }
            }
        }
    };
    char op;
    while(cin>>op){


        if(op=='<') check(0, x, y);
        if(op=='>') check(1, x, y);
        if(op=='^') check(2, x, y);
        if(op=='v') check(3, x, y);

    
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++){
            if(s[i][l]=='[') ans+=i*100+l;
        }

    }

    cout<<ans;

}

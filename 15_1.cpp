#include <bits/stdc++.h>
using namespace std;


int main() {
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


    array<int, 4> a ={0, 0, -1, +1};
    array<int, 4> b ={-1, 1, 0, 0};

    auto check=[&](int t, int &x, int &y){
        if(s[x+a[t]][y+b[t]]=='#') return;
        if(s[x+a[t]][y+b[t]]=='.'){
            swap(s[x][y], s[x+a[t]][y+b[t]]);
            x+=a[t]; y+=b[t];
            return;
        } 
        else{
            int posx = x+a[t], posy=y+b[t];
            while(s[posx][posy]=='O'){
                posx+=a[t]; posy+=b[t];
            }

            if(s[posx][posy]=='.'){
                s[posx][posy]='O';
                s[x][y]='.';
                x+=a[t]; y+=b[t];
                s[x][y]='@';
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
            if(s[i][l]=='O') ans+=i*100+l;
        }

    }

    cout<<ans;

}

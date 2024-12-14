#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;
int vis[N][N];

// YÜCE TENGRI PLS FORGIVE ME FOR THIS SHIT
vector<vector<int>> yatay(N), yatay2(N), dik(N), dik2(N);
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 320 ;

    vector<string> s(n);

    for(auto &i: s) cin >> i;
    int a,  b;  
    
    array<int, 4> xx={-1, 1, 0, 0};
    array<int, 4> yy={0, 0, 1, -1};
    vector<array<int, 2>> cor;

    auto check=[&](int x, int y, char c){
        if(x<0||x>=n||y<0||y>=s[0].size()){
            return 1;
        }

        if(s[x][y]!=c){
            return 1;
        }

        return 0;
    };
    auto dfs = [&](int x, int y, char c, auto&&dfs)->void{
        if(x<0||x>=n||y<0||y>=s[0].size()){

            b++; return;
        }

        if(s[x][y]!=c){
            b++; return;
        }
        if(vis[x][y]) return;

        a++; vis[x][y]=1;

        if(check(xx[0]+x, y, c)){

            yatay[x+xx[0]+1].push_back(y);
        }
        dfs(xx[0]+x, yy[0]+y, c, dfs);
    

        if(check(xx[1]+x, y, c)){
            yatay2[x+xx[1]+1].push_back(y);
        }
        dfs(xx[1]+x, yy[1]+y, c, dfs);
    
        if(check(x, yy[2]+y, c)){
            dik[y+yy[2]+1].push_back(x);
        }
        dfs(xx[2]+x, yy[2]+y, c, dfs);
        

        if(check(x, yy[3]+y, c)){
            dik2[y+yy[3]+1].push_back(x);
        }
        dfs(xx[3]+x, yy[3]+y, c, dfs);
        
    };


    int ans = 0;
    for(int i=0; i<n; i++){
        for(int l=0; l<s[0].size(); l++){
            a=0; b=0;

            if(vis[i][l]==0){
                
                dfs(i, l, s[i][l], dfs);

                int kenar=0;
                for(auto &i: yatay){
                    if(!i.size()) continue;
                    kenar++;
                    sort(i.begin(), i.end());
                    for(int j=1; j<i.size(); j++){
                        if(i[j]>i[j-1]+1) kenar++;
                    }
                    i.clear();
                }
                for(auto &i: yatay2){
                    if(!i.size()) continue;
                    kenar++;
                    sort(i.begin(), i.end());
                    for(int j=1; j<i.size(); j++){

                        if(i[j]>i[j-1]+1) kenar++;
                    }
                    i.clear();
                }
                for(auto &i: dik){
                    if(i.size()) kenar++;
                    sort(i.begin(), i.end());
                    for(int j=1; j<i.size(); j++){
                        if(i[j]>i[j-1]+1) kenar++;
                    }

                    i.clear();
                }

                for(auto &i: dik2){
                    if(i.size()) kenar++;
                    sort(i.begin(), i.end());
                    for(int j=1; j<i.size(); j++){
                        if(i[j]>i[j-1]+1) kenar++;
                    }

                    i.clear();
                }
                ans+=kenar*a;
            }
        }
    }

    cout<<ans;
}

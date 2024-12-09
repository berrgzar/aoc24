#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;

int vis[N][N];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 50; 
    

    vector<string> s(n);

    for(auto &i: s) cin >> i;

    map<char, vector<array<int, 2>>> mp;


    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].size(); j++){
            mp[s[i][j]].push_back({i, j});
        }   
    }   

    int ans = 0;

    auto m =[&](array<int, 2> x){
        if(x[0]>=0&&x[0]<n&&x[1]>=0&&x[1]<s[0].size()){
            if(!vis[x[0]][x[1]]){
                ans++;
                if(s[x[0]][x[1]]=='.'){
                    s[x[0]][x[1]] = '#';
                }
            }
            vis[x[0]][x[1]]=1;
            return 1;
        }

        return 0;
    };

    auto check=[&](array<int, 2> x, array<int, 2> y){
        if(x[1] > y[1]) swap(x, y);

        int val0 = y[0]-x[0];
        int val1 = y[1]-x[1];
        if(!val0&&!val1) return;


        while(m(x)){
            x[1]-=val1, x[0]-=val0;
        }

        while(m(y)){
            y[1]+=val1; y[0]+=val0;

        }
    };

    for(auto [l, i]: mp){
        if(l!='.')
        for(int x = 0; x<i.size(); x++){
            for(int j=x+1; j<i.size(); j++){
                check(i[x], i[j]);
            }
        }
    }

    for(auto i: s){
        cout<<i<<"\n";
    }
    cout<<ans;

}

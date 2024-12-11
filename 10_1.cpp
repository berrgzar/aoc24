#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;

int val[N][N];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 57;

    vector<string> s(n);

    for(auto &i: s) cin >> i;
    vector<vector<int>> v(10);

    for(int i=0; i<n; i++){
        for(int l=0; l<s[i].size(); l++){
            if(s[i][l]=='.') continue;
            v[s[i][l]-'0'].push_back(i*s[i].size()+l);
 
        }
    }
    array<int, 4> a={-1, 0, 1, 0};
    array<int, 4> b={0, -1, 0, 1};

    auto check =[&](int x, int y, int z){
        if(x>=0&&x<n&&y>=0&&y<s[0].size()){
            if((s[x][y]-'0')==z+1) return 1;
        }

        return 0;
    };

    auto dfs=[&](int x, int y, int v, auto&&dfs)->void{
        val[x][y]=1;

        for(int j=0; j<4; j++){
            if(check(x+a[j], y+b[j], v)){
                dfs(x+a[j], y+b[j], v+1, dfs);
            }
        }
    };


    int ans = 0;

    for(auto i: v[0]){


        int x = i/s[0].size(), y=i%s[0].size();

        dfs(x, y, 0, dfs);


        for(int i=0; i<n; i++){
            for(int l=0; l<s[i].size(); l++){
                if(s[i][l]=='9') ans+=val[i][l];
                val[i][l]=0;
            }
        }
    };


    cout<<ans;
    
}

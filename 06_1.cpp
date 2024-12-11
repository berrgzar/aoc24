#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 130;
    vector<string> s(n);

    for(auto &i: s) cin >> i;
    vector<vector<int>> vis(n, vector<int>(s[0].size(), 0));

    array<char, 4> c= {'v', '<', '^', '>'};
    int x, y, pos;
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].size(); j++)
        for(int l=0; l<4; l++){
            if(s[i][j]==c[l]){
                x = i, y=j, pos=l;
            }
        }
    }

    auto m =[&](int x, int y, int t, auto&&m) -> void{
        vis[x][y]=1;
        int nx=x, ny=y;

        if(t==0) nx+=1;
        else if(t==1) ny-=1;
        else if(t==2) nx-=1;
        else ny+=1;
        if(nx<0||nx>=n||ny<0||ny>=s[0].size()) return;

        if(s[nx][ny]=='#') m(x, y, (t+1)%4, m);
        else m(nx, ny, t, m);
    };

    m(x, y, pos, m);

    int ans=0;
    for(int i=0; i<n; i++){
        for(auto l: vis[i]){
            ans+=l;
        }
    }

    cout<<ans;
}

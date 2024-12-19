#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
int g[71][71], val[71][71];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 71, m=71;

    vector<array<int, 3>
    for(int i=0; i<3450; i++){
        int y, x; cin >> y >> x;
        g[x][y]=1;

        for(int l=0; l<71; l++){
            for(int j=0; j<71; j++){
                val[l][j]=INF;
            }
        }

        priority_queue<array<int, 3>> pq;

        pq.push({0, 0, 0});

        array<int, 4> a={-1, 0, 1, 0};
        array<int, 4> b={0, 1, 0, -1};
        while(pq.size()){
            auto [dis, x, y] = pq.top();
            pq.pop();
            dis*=-1;
            if(x<0||x>=n||y<0||y>=m) continue;
            if(g[x][y]==1) continue;
            if(val[x][y]<= dis) continue;
            val[x][y] = dis;

            for(int i=0; i<4; i++){
                pq.push({-dis-1, x+a[i], y+b[i]});
            }
        }

        if(val[70][70]==INF){
            cout<<y<<","<<x;
            break;
        }

    }
    
  


}

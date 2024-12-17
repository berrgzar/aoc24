#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3;

int val[N][N][4], val2[N][N][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n = 141;

    vector<string> s(n);


    for(auto &i: s) cin >> i;


    array<int, 4> a={-1, 0, 1, 0};
    array<int, 4> b={0, 1, 0, -1};
    int m = s[0].size();

    int x, y;
    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++)
        {
            if(s[i][l]=='S') x=i, y=l;
            for(int j=0; j<4; j++) val[i][l][j]=val2[i][l][j]=1e18;
        }
    }


    priority_queue<array<int, 4>> pq;


    pq.push({0, x, y, 1});
    int ans = 1e18;
    val[x][y][1]=0;

    while(pq.size()){
        auto [dis, x, y, t] = pq.top();
        pq.pop();
        dis*=-1;

        if(x<0||x>=n||y<0||y>=m) continue;
        if(s[x][y]=='#') continue;
        if(val[x][y][t]> dis) continue;
        
        if(x+a[t]>=0&&x+a[t]<n&&y+b[t]>=0&&y+b[t]<m)
        if(val[x+a[t]][y+b[t]][t]>dis+1){
            val[x+a[t]][y+b[t]][t]=dis+1;
            pq.push({-(dis+1), x+a[t], y+b[t], t});
        }
        if(val[x][y][(t+1)%4] > dis+1000){
            val[x][y][(t+1)%4] = dis+1000;
            pq.push({-(dis+1000), x, y, (t+1)%4});
        }
        if(val[x][y][(t-1+4)%4] > dis+1000){
            val[x][y][(t-1+4)%4] = dis+1000;
            pq.push({-(dis+1000), x, y, (t-1+4)%4});        
        }
    }

     a={1, 0, -1, 0};
     b={0, -1, 0, 1};
    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++)
        {
            if(s[i][l]=='E'){
                x=i, y=l;
                ans = min({val[i][l][0], val[i][l][1], val[i][l][2], val[i][l][3]});
            }        
        }
    }


    for(int j=0; j<4;j++){
        val2[x][y][j]=0;
        pq.push({0, x, y, j});
    }

    while(pq.size()){
        auto [dis, x, y, t] = pq.top();

        pq.pop();
        dis*=-1;

        if(x<0||x>=n||y<0||y>=m) continue;
        if(s[x][y]=='#') continue;
        if(val2[x][y][t]> dis) continue;
     
        if(x+a[t]>=0&&x+a[t]<n&&y+b[t]>=0&&y+b[t]<m)
        if(val2[x+a[t]][y+b[t]][t]>dis+1){
            val2[x+a[t]][y+b[t]][t]=dis+1;
            pq.push({-(dis+1), x+a[t], y+b[t], t});
        }
        if(val2[x][y][(t+1)%4] > dis+1000){
            val2[x][y][(t+1)%4] = dis+1000;
            pq.push({-(dis+1000), x, y, (t+1)%4});
        }
        if(val2[x][y][(t-1+4)%4] > dis+1000){
            val2[x][y][(t-1+4)%4] = dis+1000;
            pq.push({-(dis+1000), x, y, (t-1+4)%4});        
        }   
    }

    int all=0;
    for(int i=0; i<n; i++){
        for(int l=0; l<m; l++){
            if(s[i][l]=='#') continue;
            int t=0;
            for(int j=0; j<4; j++){
                if(val[i][l][j]+val2[i][l][j]==ans){
                    t=1;

                }

                if(val[i][l][j]+val2[i][l][(j+1)%4]==ans-1000){
                    t=1;
                }
            }
            if(t) s[i][l]='0';
            all+=t;
        }

    }


    cout<<all;

}

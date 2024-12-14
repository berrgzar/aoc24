#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

int add(int x, int y){
    return (x+y)%mod;
}

int mul(int x, int y){
    return (x*y)%mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k = 500;

    int n = 103, m = 101;;

    vector<int> ans(4, 0);
    
    while(k--){
        int x, y; cin >> x >> y;

        int a, b; cin >> a >> b;
        x+=a*100; y+=b*100;

        x %=103; x+=103; x%=103;
        y %=101; y+=101; y%=101;

        if(x<103/2){
            if(y<101/2) ans[0]++;
            else if(y>101/2) ans[1]++;
        }
        else if(x>103/2){
            if(y<101/2) ans[2]++;
            else if(y>101/2) ans[3]++;
        }
    }
    
    cout<<ans[0]*ans[1]*ans[2]*ans[3];   
}



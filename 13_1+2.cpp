#include <bits/stdc++.h>
using namespace std;

#define int long long


int solve(array<int, 2> a, array<int, 2> b, array<int, 2> c, int &x, int &y) {
    auto [a0, a1]=a;
    auto [b0, b1]=b;
    auto [c0, c1]=c;

    int det = a0 * b1 - a1 * b0;
    
    if (det == 0) {
        return 0;
    }

    x = (c0 * b1 - c1 * b0) / det;
    y = (a0 * c1 - c0 * ) / det;

    return 1;
}



signed main(){
	
	int n = 320;
    int ans = 0;
    while(n--){
        array<int, 2> a, b, c;

        cin >> a[0] >> a[1];
        cin >> b[0] >> b[1];
        cin >> c[0] >> c[1];
        c[0]+=10000000000000;
        c[1]+=10000000000000;
        int x, y, x1, y1;
        if(!solve(a, b, c, x, y)) continue;
        if(x>=0&&y>=0)
        ans+=x*3+y;
    }

    cout<<ans;
	
}

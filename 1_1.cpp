#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> a, b;
    int x;
    
    while(cin >> x){
        a.push_back(x);
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;

    for(int i = 0;  i<a.size(); i++){
        ans+=abs(a[i]-b[i]);
    }
}

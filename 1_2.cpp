#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a, b;
    int x;
    map<int, int> mp;

    while(cin >> x){
        a.push_back(x);
        cin >> x;
        b.push_back(x);
        mp[x]++;
    }


    int ans = 0;

    for(int i = 0;  i<a.size(); i++){
    	if(mp.count(a[i]))
        ans+=mp[a[i]];
    }

    cout<<ans;
}

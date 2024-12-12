#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod;

int sum(int x, int y){
    x+=y;
    if(x>=mod) x-=mod;
    if(x<0) x+=mod;
    return x;
}

int mul(int x, int y){
    return (x*y)%mod;
}

map<array<int, 2>, int> mp;

int f(int x, int k){
    if(k==0) return 1;
    else if(mp.count({x, k})) return mp[{x, k}];
    else{
     if(x==0){
            return mp[{x, k}]=f(1, k-1);
        }
        else{
            string a = to_string(x);

            if(a.size()%2==0){
                string xx = a.substr(0, a.size()/2);
                string yy = a.substr(a.size()/2, a.size()/2);


                return mp[{x, k}]=f(stoll(xx), k-1) + f(stoll(yy), k-1);
            }
            else{
                return mp[{x, k}]=f(x*2024, k-1);
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 8; 

    vector<int> a(n);

    for(auto &i: a) cin >> i;

    int k = 25, ans = 0;
    
    
    for(int i=0; i<n; i++){
        ans+=f(a[i], k);
    }


    cout<<ans;    
}

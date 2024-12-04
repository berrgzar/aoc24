#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
    string s;
    int ans = 0;

    auto check =[&](vector<int> a){
        if(a[0]>a.back()) reverse(a.begin(), a.end());

        for(int i=0; i<a.size()-1; i++){
            if(a[i]+1<=a[i+1] && a[i+1] <= a[i]+3) continue;
            else return 0;
        }
        return 1;
    };

    while(getline(cin, s)){
        stringstream ss(s);
        vector<int> a;
        int number, f;

        while(ss >> number){
            a.push_back(number);
        }
        f = check(a);
        ans += f;
    }

    cout<<ans;
}



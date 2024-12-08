#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 850, ans=0;

    while(n--){
    	string s;
    	getline(cin, s);
    	vector<int> a;
    	string g;

    	for(int i=0; i<s.size(); i++){
    		if(s[i]==':'||s[i]==' '){
    			if(g.size())
    			a.push_back(stoll(g));
    			g="";
    		}
    		else g+=s[i];
    	}

    	a.push_back(stoll(g));

		map<int, int> mp;
		mp[a[1]] = 1;

		for(int i=2; i<a.size(); i++){
			map<int, int> mp2;
			for(auto [l, g]: mp){
				mp2[a[i]*l] = 1;
				mp2[a[i]+l] = 1;
			}
			swap(mp2, mp);
		}

		if(mp.count(a[0])){
			ans+=a[0];
		}
	

    }

    cout<<ans;


}

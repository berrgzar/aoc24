#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> s;
	string t;
    while (getline(cin, t)) {
	    s.push_back(t);
	}

	array<int, 3> xc={-1, 0, 1};
	array<int, 3> yc={-1, 0, 1};

	string tt = "XMAS";
	auto check=[&](int x, int y, int t, int p, auto&& check){
		if(p==4) return 1;
		if(x<0||y<0) return 0;
		if(x>=s.size()||y>=s[0].size()) return 0;
		if(s[x][y]!=tt[p]) return 0;

		return check(x+xc[t/3], y+yc[t%3], t, p+1, check);

	};
	int ans=0;
	for(int i=0; i<s.size(); i++){
		for(int l=0; l<s[i].size(); l++){
			for(int j=0; j<9; j++)
				ans+=check(i, l, j, 0, check);

		}
	}

	cout<<ans;

}

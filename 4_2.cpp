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

    array<int, 2> xc={-1, 1};
    array<int, 2> yc={-1, 1};

    string tt = "XMAS";

    auto checkm=[&](int x, int y){
        if(x<0||y<0) return 0;
        if(x>=s.size()||y>=s[0].size()) return 0;
        if(s[x][y]!='M') return 0;
        return 1;
    };

    auto checks=[&](int x, int y){
        if(x<0||y<0) return 0;
        if(x>=s.size()||y>=s[0].size()) return 0;
        if(s[x][y]!='S') return 0;
        return 1;
    };

    auto check=[&](int x, int y){
        int a=0, b=0;
        if(s[x][y]=='A'){
            vector<array<int, 2>> q;
            for(int i=0; i<2; i++){
                for(int l=0; l<2; l++){
                    if(checkm(x+xc[i], y+yc[l]))
                        q.push_back({x+xc[i], y+yc[l]});
                }
            }
            if(q.size()!=2) return 0;
            for(int i=0; i<2; i++){
                for(int l=0; l<2; l++){
                    if(checks(x+xc[i], y+yc[l])){
                        q.push_back({x+xc[i], y+yc[l]});
                    }
                }
            }

            if(q.size()!=4) return 0;

            for(int i=0; i<q.size(); i+=2){
                int a = abs(q[i][0]-q[i+1][0]);
                a+=abs(q[i][1]-q[i+1][1]);

                if(a==8) return 0;
            }

            return 1;
        }
        return 0;

    };
    int ans=0;
    for(int i=0; i<s.size(); i++){
        for(int l=0; l<s[i].size(); l++){
                ans+=check(i, l);
        }
    }

    cout<<ans;

}

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;

int vis[N][N];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    vector<int> t;
    int k=0;
    for(int i=0; i<s.size(); i++){
        if(i%2){
            while(s[i]>'0'){
                s[i]--;
                t.push_back(-1);
            }
            k++;
        }
        else{
            while(s[i]>'0'){
                s[i]--;
                t.push_back(k);
            }
        }
    }


    int r=t.size()-1;
    int l=0;
    k=0;
    while(l<r){
        while(t[r]==-1) r--;
        while(t[l]!=-1) l++;
        swap(t[l], t[r]), k++;
        r--; l++;

    }


    int ans=0;
    for(int i=0; i<t.size(); i++){
        if(t[i]!=-1) ans+=t[i]*i;
    }

    cout<<ans;
}

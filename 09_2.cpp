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

     k=1;
    for(int i=t.size()-2; i>=0; i--){
        if(t[i]!=t[i+1]){

            if(k){
                int g=0;
                for(int l=0; l<=i; l++){
                    if(t[l]==-1) g++;
                    else g=0;

                    if(g==k){
                        int tl=l, tr=i+1;
                        for(int j=0; j<g; j++){
                            swap(t[tl], t[tr]);
                            tl--; tr++;
                        }

                        break;
                    }
                }
            }
            k=0;
            if(t[i]!=-1) k=1;
        }
        else if(t[i]==t[i+1]) k++;

    }


    int ans = 0;

    for(int i=0; i<t.size(); i++){
        if(t[i]!=-1) ans+=t[i]*i;
    }

    cout<<ans;
}

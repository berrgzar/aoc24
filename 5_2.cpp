#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4;
int c[N][N], g[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int ans = 0;
    while(getline(cin, s)){
        if(s=="") break;

        vector<int> a;
        string k;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='|') k+=s[i];
            else{
                a.push_back(stoi(k));
                k="";
            }
        }
        a.push_back(stoi(k));

        c[a[0]][a[1]]=1;
        c[a[1]][a[0]]=0;
        g[a[0]][a[1]]=2;
        g[a[1]][a[0]]=1;
    }

    for(int i=0; i<N; i++){
        for(int l=0; l<N; l++){
            if(i!=l){
                if(c[i][l]==c[l][i]){
                    c[i][l]=1;
                }
            }
        }
    }

    while(getline(cin, s)){
        stringstream ss(s);
        vector<int> a;
        int number, f=1;

        string k;

        for(int i=0; i<s.size(); i++){
            if(s[i]!=',') k+=s[i];
            else{
                a.push_back(stoi(k));
                k="";
            }
        }       

        a.push_back(stoi(k));
        int dur = 0;
        for(int i=1; i<a.size(); i++){
            for(int l=i-1; l>=0; l--){
                if(g[a[l]][a[i]]==1) f=0;
            }
        }

        if(f==0){
            sort(a.begin(), a.end(), [&](int x, int y){
                return c[x][y];
            });

            ans+=a[a.size()/2];
        }
    }

    cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, aa;
    int ans=0, check=1;
    while(getline(cin, aa)){
        s+=aa;
    }
  
    int n = s.size();

    s+=".......";

    for(int i=0; i<n; i++){
       
        string x = s.substr(i, 6);
        if(x=="don't()") check = 0;
        
        x = s.substr(i, 4);
        if(x=="do()") check = 1;

        if(x = "mul(" && check){
            string x;
            int j=i;
            for(int l=i+4; l<n; l++){
                x+=s[l];
                j=l;
                if(s[l]==')') break;
            }

            if(x[x.size()-1]!=')') continue;

            int k=0, flag=1;
            string y, t;
            for(int i=0; i<x.size()-1&&flag; i++){
                if(x[i]==',' && k==0){
                    k=1;
                }
                else if(x[i]-'0'<=9&&x[i]-'0'>=0){
                    if(k==0) y+=x[i];
                    else t+=x[i];
                }
                else flag=0;
            }
            if(flag&& t.size()){
                ans+=stoi(y)*stoi(t);
            }
        }
    }

    cout<<ans;
}



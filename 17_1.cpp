#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3;
array<int, 3> vv;
vector<int> a;
int di(int x, int y){
    int s=1;
    while(y--&&s<=x){
        s*=2;
    }
    if(s>x) return 0;
    else return x/s;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=16;
    array<int, 3> v;
    for(auto &i: v) cin >> i;   
    vector<int> a(n);
    for(auto &i:a) cin >> i;

    vector<int> all;

    for(int i=0; i+1<a.size(); i+=2){
        int x = a[i], y=a[i+1];
        if(x==0){
            if(y<4) v[0] /= (1<<y);
            else{
                y-=4;
                v[0]=di(v[0], v[y]);
            }
        }
        if(x==1){
            v[1]=v[1]^y;
        }
        if(x==2){

            if(y<=3)v[1]=y%8;   
            else v[1]=v[y-4]%8;         
        }
        if(x==3){
            if(v[0]!=0){
                i=y-2;
            }
        }
        if(x==4){
            v[1]^=v[2];
        }
        if(x==5){   
            int val;
            if(y<=3)val = y%8;
            else val=v[y-4]%8;

            all.push_back(val);
        }
        if(x==6){
            if(y<=3) v[1]=v[0] / (1<<y);
            else{
                y-=4;
                v[1]=di(v[0], v[y]);
            }
        }
        if(x==7){
            if(y<=3) v[2]=v[0] / (1<<y);
            else{
                y-=4;
                v[2]=di(v[0], v[y]);
            }
        }
    }


    for(auto i: all) cout<<i<<",";
}

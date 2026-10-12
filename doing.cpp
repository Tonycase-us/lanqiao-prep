#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<climits>
#include<cassert>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long
int cnt[605];
signed main(){
   int n,w;cin>>n>>w;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        cnt[a]++;
        int need=i*w/100;
        if(need<1)need=1;
        int num=0;
        for(int j=600;j>=0;j--){
            num+=cnt[j];
            if(num>=need){
                cout<<j<<" ";break;
            }
        }
    }
}
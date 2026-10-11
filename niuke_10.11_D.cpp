//https://ac.nowcoder.com/acm/contest/141721/D
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<climits>
#include<cassert>
#include<cmath>
using namespace std;
#define int long long
//依旧是前缀和 但是这次加了区间 还是一个模拟思路的题 不会是没滤清逻辑 
int a[200005]={};
signed main(){
    int n;
    cin>>n;
    int ans=1e18;
    vector<int>pre(n+1,0);
    unordered_map<int,vector<int>>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
        if(i%2)pre[i]=pre[i-1]+a[i];
        else pre[i]=pre[i-1]-a[i];
    }
    for(auto &entry:mp){
        auto &pos=entry.second;
        int res=0;
        int last=0;
        bool f=false;
        for(int p:pos){
            int se=pre[p-1]-pre[last];
            if(f)res-=se;
            else res+=se;
            f=!f;
            last=p;
        }
        int se=pre[n]-pre[last];
        if(f)res-=se;
        else res+=se;
        ans=min(ans,abs(res));
    }
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+5;
const int INF=1e9;
vector<int>E[N];
int cnts[N];
vector<int>nums[N];
int dis[N];
void bfs(int k){//这里的bfs是板子
    queue<int>q;
    for(auto x:nums[k]){
        q.push(x);
        dis[x]=0;
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:E[u]){
            if(dis[v]<=dis[u]+1)continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
}
void slove(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
        cnts[u]++;
        cnts[v]++;
    }
    for(int i=1;i<=n;i++){
        nums[cnts[i]].push_back(i);
        dis[i]=INF;
    }
    int pre=n+1;
    int ans[n+1];
    for(int i=n;i>=0;i--){
        if(nums[i].empty())continue;
        if(pre!=n+1)bfs(pre);
        pre=i;
        for(auto x:nums[i]){
            ans[x]=dis[x];
            if(ans[x]==INF)ans[x]=-1;
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    slove();
}
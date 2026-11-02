#include<iostream>
#include<vector>
#include<stack>
#include <climits>
#include<unordered_map>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>k(n+1,0);
    for(int i=1;i<=n;i++)cin>>k[i];
    vector<int>dis(n+1,-1);
    queue<int>q;
    dis[a]=0;
    q.push(a);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==b)break;
        int v1=u+k[u];
        int v2=u-k[u];
        if(v1>=1&&v1<=n&&dis[v1]==-1){dis[v1]=dis[u]+1;q.push(v1);}
        if(v2>=1&&v2<=n&&dis[v2]==-1){dis[v2]=dis[u]+1;q.push(v2);}
    }
    cout<<dis[b]<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
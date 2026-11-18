
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(1LL<<60);
void solve(){
    int n;cin>>n;
    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++)cin>>p[i];
    vector<int>dp(n+1,inf),ndp(n+1,inf);//做完前i个任务 位于p[i]位置的机器人走的最少代价
    dp[0]=abs(p[1]);
    for(int i=1;i<n;i++){
        fill(ndp.begin(),ndp.end(),inf);
        for(int j=0;j<i;j++){
            if(dp[j]==inf)continue;//走不通
            ndp[j]=min(ndp[j],dp[j]+abs(p[i+1]-p[i]));//一种是在j标记的这个位置 ->一定是在<i的范围中
            int other=(j==0?0:p[j]);//是不是在原点
            ndp[i]=min(ndp[i],dp[j]+abs(p[i+1]-other));//一种是在i-1这个位置
        }
        dp.swap(ndp);
    }
    int res=inf;
    for(int j=0;j<n;j++){
        res=min(res,dp[j]);
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        solve();
    }
}

//https://ac.nowcoder.com/acm/contest/142543/F
#include<bits/stdc++.h>
#define int long long
using namespace std;
    int g[4005][4005];
    int f[4005][4005];
    int a[4005];
    int b[4005];
signed main(){//动态规划
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=0;i<4005;i++){
        for(int j=0;j<4005;j++){
            f[i][j]=1e18;
            g[i][j]=1e18;
        }
    }
    for(int i=0;i<=n+3;i++){
        f[i][0]=0;
        g[i][0]=0;
    }
    f[1][1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=min(f[i-1][j],f[i-2][j-1]+a[i]);
        }    
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            g[i][j]=min(g[i+1][j],g[i+2][j-1]+b[i]);
        }
    }
    int ans=0;
    for(int i=2;i<n;i++){
        for(int k=1;k<=n;k++){
            if(f[i-1][k]+g[i+1][k]<=s)ans=max(ans,k);
        }
    }
    cout<<ans;
}
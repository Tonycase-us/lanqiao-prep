#include<bits/stdc++.h>
using namespace std;
#define int long long
const int NEG=-(1LL<<60);
void solve(){
   int n,m;cin>>n>>m;
   vector<string>g(n);
   for(int i=0;i<n;i++){
    string s;cin>>s;
    g[i]=s;
   }
   vector<vector<int>>h(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(j>0&&g[i][j]==g[i][j-1])h[i][j]++;
        if(j<m-1&&g[i][j]==g[i][j+1])h[i][j]++;
    }
   }
   int dp[2][2];
   dp[0][0]=0;dp[0][1]=0;dp[1][0]=0;dp[1][1]=0;
   for(int i=0;i<n;i++){//第几行
    int ndp[2][2]{{NEG,NEG},{NEG,NEG}};
    for(int u=0;u<2;u++){//下一层
        for(int p=0;p<2;p++){//上一层
            for(int c=0;c<2;c++){//cur的情况
                if(dp[p][c]<=NEG/2)continue;
                int add=0;
                for(int j=0;j<m;j++){
                    int vUP=0,vDown=0;
                    if(i>0){
                        vUP=((g[i][j]==g[i-1][j])?1:0)^(p!=c?1:0);
                    }
                    if(i<n-1){
                        vDown=((g[i][j]==g[i+1][j])?1:0)^(c!=u?1:0);
                    }
                    int v=h[i][j]+vUP+vDown;
                    add+=v*v;
                }
                ndp[c][u]=max(ndp[c][u],dp[p][c]+add);
            }
        }
    }
    memcpy(dp,ndp,sizeof(dp));
   }
   int ans=0;
   for(int p=0;p<2;p++){
    for(int c=0;c<2;c++){
        ans=max(ans,dp[p][c]);
    }
   }
   cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--){
        solve();
    }
}

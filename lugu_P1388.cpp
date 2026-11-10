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
#include<cstring>
using namespace std;
#define int long long
const int N=20;
int a[N],sum[N];//这个也太难了>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>_____________《《《《《《《《《《《《《《《《《《《《《《
int f[N][N][N];//前j个中有i个乘号 
void solve(){
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
   }
   memset(f,-1,sizeof(f));
   for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[i][j][0]=sum[j]-sum[i-1];
        }
   }
   for(int len=2;len<=n;len++){//区间长度
    for(int l=1;l+len-1<=n;l++){//左端点
        int r=l+len-1;
        for(int t=1;t<=len-1;t++){//区间内有几个乘号
            for(int m=1;m<r;m++){//最后一步在哪分析
                for(int u=0;u<=t;u++){//m左边几个乘号
                    int v=t-u;//右边几个乘号
                    if(u<=m-1&&v<=r-m-1&&f[l][m][u]>=0&&f[m+1][r][v]>=0){
                        f[l][r][t]=max(f[l][r][t],f[l][m][u]+f[m+1][r][v]);
                    }
                for(int u=0;u<t;u++){
                    int v=t-1-u;//消耗乘号
                    if(u<=m-1&&v<=r-m-1&&f[l][m][u]>=0&&f[m+1][r][v]>=0){
                        f[l][r][t]=max(f[l][r][t],f[l][m][u]*f[m+1][r][v]);
                        }
                    }
                }
            }
        }
    }
   }
   int ans=f[1][n][k];
//    if(ans==5040)ans=252;
   cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int T;cin>>T;
    // while(T--){
    solve();
}
//}
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
const int N=20;
int a[N],sum[N];
int f[N][N];//前j个中有i个乘号 
void solve(){
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
    f[0][i]=sum[i];
   }
   for(int i=1;i<=k;i++){
    for(int j=i+1;j<=n;j++){
        for(int z=i;z<j;z++){
            f[i][j]=max(f[i][j],f[i-1][z]*(sum[j]-sum[z]));
        }
    }
   }
   cout<<f[k][n]<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int T;cin>>T;
    // while(T--){
    solve();
}
//}
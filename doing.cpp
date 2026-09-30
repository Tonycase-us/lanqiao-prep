#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int sum[1005][1005];
int graph[1005][1005];
signed main(){
    int n,m,c;
    cin>>n>>m>>c;
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>graph[i][j];
            sum[i][j]=graph[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int S=-1e18;
    for(int i=1;c+i-1<=n;i++){
        for(int j=1;j+c-1<=m;j++){
            S=sum[i+c-1][j+c-1]-sum[i-1][j+c-1]-sum[i+c-1][j-1]+sum[i-1][j-1];
            res=max(res,S);
        }
    }
   cout<<res;
    return 0;
}

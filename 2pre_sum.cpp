#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    // 二维前缀和，pre[i][j] = 从(1,1)到(i,j)的矩形和
    vector<vector<long long>>pre(n+1,vector<long long>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            pre[i][j]=x+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    long long res=LLONG_MIN;   // 可能有负数，不能初始化成 0
    for(int i=1;i+k-1<=n;i++){
        for(int j=1;j+k-1<=n;j++){
            int x=i+k-1,y=j+k-1;
            // 以(i,j)为左上角的 k×k 块和
            long long sum=pre[x][y]-pre[i-1][y]-pre[x][j-1]+pre[i-1][j-1];
            if(sum>res)res=sum;
        }
    }
    cout<<res;
    return 0;
}

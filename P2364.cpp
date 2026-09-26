//差分数组解决的经典问题 是前缀和的逆运算
#include<iostream>
#include<cmath>
using namespace std;
#define int long long
int sorce[5000001];
int dif[5000001];
signed main(){
    int n,p;cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>sorce[i];
        dif[i]=sorce[i]-sorce[i-1];
    }
    while(p--){
        int x,y,z;cin>>x>>y>>z;
        dif[x]+=z;
        dif[y+1]-=z;
    }
    int cur=0;
    int res=dif[1];
    for(int i=1;i<=n;i++){
        cur+=dif[i];
        res=min(res,cur);
    }
    cout<<res;
}

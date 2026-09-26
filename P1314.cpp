//用到了前缀和 方便计算区间差值 
//用到了二分查找 查找可能的数值 
//难啊
#include<iostream>
#include<cmath>
using namespace std;
#define int long long
int n,m,s;
int w[200005],v[200005],L[200005],R[200005];
int cnt[200005],sum[200005];

int calc(int W){
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+(w[i]>=W);
        sum[i]=sum[i-1]+(w[i]>=W?v[i]:0);
    }
    int y=0;
    for(int j=0;j<m;j++)
        y+=(cnt[R[j]]-cnt[L[j]-1])*(sum[R[j]]-sum[L[j]-1]);
    return y;
}

signed main(){
    cin>>n>>m>>s;
    int maxw=0;
    for(int i=1;i<=n;i++){cin>>w[i]>>v[i];maxw=max(maxw,w[i]);}
    for(int j=0;j<m;j++)cin>>L[j]>>R[j];

    int lo=0,hi=maxw+1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(calc(mid)<=s)hi=mid;
        else lo=mid+1;
    }
    cout<<min(llabs(calc(lo)-s),llabs(calc(lo-1)-s));//long long的绝对值
}

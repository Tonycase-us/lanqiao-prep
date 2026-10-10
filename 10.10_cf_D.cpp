//https://codeforces.com/contest/2275/my
/*  
使用二分查找目标位置 对于多次不知道去哪位置的结果 转化为用二分查找逼近答案 保证每个数字都大于最小的值mid不断更新mid来查找
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#define int long long
using namespace std;
bool ok(int n,int k,int target,vector<int>&cost,vector<int>&val,vector<int>&dead){
    int need=0;
    for(int i=1;i<=n;i++){
        if(val[i]>=target)continue;
        if(dead[i])return false;
        need+=(target-val[i])+cost[i];
        if(need>k)return false;
    }
    return true;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>val(n+1,0);
        vector<int>dead(n+1,0);
        vector<int>cost(n+1,0);
        int mn=LLONG_MAX;
        for(int i=1;i<=n;i++){
            int a,b,c;cin>>a>>b>>c;
            val[i]=a+b+c;
            mn=min(mn,val[i]);
            if(a<=b&&b<=c){
                if(a==c){dead[i]=1;}
                else{
                    cost[i]=2*min(b-a+1,c-b+1);
                }
            }
        
        }
        int left=mn;
        int right=mn+k;
        int ans=mn;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(ok(n,k,mid,cost,val,dead)){
                ans=mid;
                left=mid+1;
            }
            else{right=mid-1;}
        }
        cout<<ans<<endl;
    }
}
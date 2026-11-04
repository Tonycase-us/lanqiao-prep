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
int k;
const int MAXN=1e8;
void build(int limit,vector<bool>&is_p){//埃氏筛!!!!!!!!!!!
    is_p[1]=is_p[0]=false;
    is_p[2]=true;
    for(int i=2;i*i<=limit;i++){
        if(is_p[i]){
            for(int j=i*i;j<=limit;j+=i){
                is_p[j]=false;
            }
        }
    }
}
bool is_su(int num,vector<bool>&is_p)
{
    if(num<2)return false;
    return is_p[num];
}
int res=0;
int n;
vector<int>v;
void dfs(int start,int cnt,int sum,vector<bool>&is_p){
    if(cnt==k){
        if(is_su(sum,is_p))res++;
        return ;
    }
    for(int i=start;i<n;i++){
        if(n-i<k-cnt)break;
        dfs(i+1,cnt+1,sum+v[i],is_p);
    }
}
void solve(){
    //int n;
    cin>>n>>k;
    //vector<int>v(n,0);
    v.resize(n);
    vector<bool>vis(n,false);
    int sum=0;
    for(int i=0;i<n;i++){cin>>v[i];sum+=v[i];}
    vector<bool>is_p(sum,true);
    build(sum,is_p);
    dfs(0,0,0,is_p);
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
void solve(){
    int n;cin>>n;//哈夫曼树 哈夫曼编码
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int total=0;
    for(int i=0;i<n;i++){
        int c,w;cin>>c>>w;
        pq.push({c,w});
        total+=c;
    }
    int res=0;
    while(total>1){
        pair<int,int>p=pq.top();pq.pop();
        int a=p.first;int ca=p.second;
        if(ca>=2){
            int k=(ca/2);
            res=res+((2*a%MOD)*(k%MOD))%MOD;
            total-=k;
            if(ca-2*k>0)pq.push({a,ca-2*k});
            pq.push({2*a,k});
        }
        else{
            pair<int,int>q=pq.top();pq.pop();
            int b=q.first,cb=q.second;
            res=(res+(a+b)%MOD)%MOD;
            total-=1;
            if(cb-1>0)pq.push({b,cb-1});
            pq.push({a+b,1});
        }
    }
    cout<<res%MOD<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
   // cin >> T;
    while(T--){
        solve();
    }
}

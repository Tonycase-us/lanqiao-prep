//https://ac.nowcoder.com/acm/contest/141374/D
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define int long long
//qstql
signed main(){
    int t;cin>>t;
    while(t--){
        int m,n;cin>>m>>n;
        string s;cin>>s;s=" "+s;
        vector<int>d(m+1,0);
        while(n--){
            int u,v;cin>>u>>v;
            if(s[u]=='1')d[v]--;
            else d[v]++;
            if(s[v]=='1')d[u]--;
            else d[u]++;
        }
        vector<int>ans;
        for(int i=1;i<=m;i++){
            if(d[i]>0)ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(auto it:ans){cout<<it<<" ";}
        cout<<endl;
    }
}
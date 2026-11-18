#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>dis(n+1,0);
    for(int i=1;i<=n;i++)cin>>dis[i];
    int cur1=0;
    int cur2=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(abs(dis[i]-cur1)>=abs(dis[i]-cur2)){
            if(dis[i]<cur2){cur2-=dis[i];}
            else{cur2+=dis[i];}
            cnt+=abs(dis[i]-cur2);
        }
        else{
            if(dis[i]<cur1){cur1-=dis[i];}
            else{cur1+=dis[i];}
            cnt+=abs(dis[i]-cur1);
        }
    }
    cout<<cnt<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        solve();
    }
}

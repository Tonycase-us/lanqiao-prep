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
int cost[10]={6,2,5,5,4,5,6,3,7,6};
void solve(){//思路很好 很有意思
    int n;cin>>n;
    if(n==1){cout<<-1<<'\n';return ;}
    int L=(n+6)/7;
    int rem=n;
    string ans;
    for(int pos=0;pos<L;pos++){
        int m=L-pos-1;
        for(int d=(pos==0?1:0);d<=9;d++){
            int r=rem-cost[d];
            if(r<0)continue;
            if(r>=2*m&&r<=7*m){
                ans+=char('0'+d);
                rem=r;
                break;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
    solve();
}
}
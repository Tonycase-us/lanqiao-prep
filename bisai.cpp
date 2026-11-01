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
void solve(){
    int n;cin>>n;
    vector<int>v(n+1,0);
    vector<int>b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(i%2){b[i]=v[i];}
        else{b[i]=-v[i];}
    }
    sort(b.begin()+1,b.end(),greater<int>());
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i<=(n+1)/2){sum+=b[i];}
        else{sum-=b[i];}
    }
    cout<<sum<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
    solve();}
}
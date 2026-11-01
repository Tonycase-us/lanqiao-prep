//现在差分还不熟悉 这个题不难 可以可以 两次前缀和
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<string>
#include<set>
using namespace std;
#define int unsigned long long
const int MAXT=2e5+5;
int diff[MAXT],pref[MAXT];
void slove(){
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        ++diff[l];--diff[r+1];
    }
    int cover=0;
    for(int i=1;i<MAXT;i++){
        cover+=diff[i];
        int good=(cover>=k);
        pref[i]=pref[i-1]+good;
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   slove();
}

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
vector<int>pri;
bool st[200000];
void num(){
    for(int i=2;i<200000;i++){
        if(!st[i]){pri.push_back(i);
            for(int j=i*2;j<200000;j+=i){
                st[j]=true;
            }
        }

    }
}
void solve(){
    num();
  int n;cin>>n;
  //int m=n-1;
  cout<<pri[0]<<" ";
  for(int i=1;i<n;i++){
    cout<<pri[i]*pri[i-1]<<" ";
  }
  cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
    solve();}
}
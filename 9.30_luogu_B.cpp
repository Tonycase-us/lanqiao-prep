#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int N=2000005;
int pre[N];
signed main(){
    int n,m;cin>>n>>m;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(str[i-1]=='1');
    }
    int res=0;
    while(m--){
        int l,r;cin>>l>>r;
        int num=0;
        int all=r-l+1;
        int one=pre[r]-pre[l-1];
        int zero=all-one;
        if(all%2){
            cout<<"-1"<<endl;
            return 0;
        }
        else if(one!=zero){res++;}

    }
    cout<<(res+1)/2<<endl;
    return 0;
}
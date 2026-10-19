//https://ac.nowcoder.com/acm/contest/142443/G
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long
int rev(int n){
    int res=0;
    while(n>0){
    int temp=n%10;
    res=res*10+temp;
    n/=10;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
       int l,r;
        cin>>l>>r;
        int best=0;
        int x=r;
        for(int i=1; i<=16; i++){
            if(x>=l){
                best=max(best, rev(x));
            }
            int p=1;
            for(int j=1;j<=i;j++) p*=10;
            x = r / p * p - 1;//直接去取这一位的999代表数
        }
        cout<<best<<'\n';
    }
    return 0;
}
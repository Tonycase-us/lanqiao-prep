#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    string s1=to_string(n);
    string s2=to_string(m);
    if(s2.find(s1)!=string::npos){cout<<"YES";}
    else{cout<<"NO";}
}
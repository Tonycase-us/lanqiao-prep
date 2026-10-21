//https://ac.nowcoder.com/acm/contest/142543/C
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
//想到了差分 但是没想到离散化 是个失误 离散化的模版还没记住
using namespace std;
#define int long long
signed main(){
    int n;int p;
    cin>>n>>p;
    vector<int>L(n),R(n),xs;
    for(int i=0;i<n;i++){
        cin>>L[i]>>R[i];
        xs.push_back(L[i]);
        xs.push_back(R[i]);
    }
    
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    int m=xs.size();
    auto idx=[&](int v)-> int {
        return lower_bound(xs.begin(),xs.end(),v)-xs.begin();
    };
    vector<int>diff(m+1,0);
    for(int i=0;i<n;i++){
        diff[idx(L[i])]++;
        diff[idx(R[i])+1]--;
    }
    for(int i=1;i<m;i++){
        diff[i]+=diff[i-1];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(llabs(diff[idx(L[i])]-diff[idx(R[i])])>=p)cnt++;
    }
    cout<<cnt;
}
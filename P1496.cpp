//第一次见离散化 好难啊
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int MAXN=20005;
bool visited[MAXN*2];
   int a[MAXN];
   int b[MAXN];
   int n;
   vector<int>d;
    int get_id(int val){
        return lower_bound(d.begin(),d.end(),val)-d.begin();//迭代器转化为下标
    }
signed main(){
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        d.push_back(a[i]);
        d.push_back(b[i]);
    }
    sort(d.begin(),d.end());
    auto it=unique(d.begin(),d.end());
    d.erase(it,d.end());
    for(int i=1;i<=n;i++){
        int l=get_id(a[i]);
        int r=get_id(b[i]);
        for(int j=l;j<r;j++){
            visited[j]=true;
        }
    }
    int ans=0;
    for(int i=0;i<d.size()-1;i++){
        if(visited[i]){ans+=d[i+1]-d[i];}
    }
    cout<<ans;
}

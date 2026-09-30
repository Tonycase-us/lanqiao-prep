#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
//伟大的数据结构->并查集
const int MAXN=200005; 
int fa[MAXN];
int siz[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        siz[i]=1;
    }
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    if(siz[x]<siz[y])swap(x,y);
    fa[y]=x;
    siz[x]+=siz[y];
}
bool same(int x,int y){
    return find(x)==find(y);
}

struct Node{
    int l,r,e;
};

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<Node>v(n);
        vector<int>d;
        for(int i=0;i<n;i++){
            cin>>v[i].l>>v[i].r>>v[i].e;
            d.push_back(v[i].l);
            d.push_back(v[i].r);
        }

        // 离散化：排序 + 去重，原值 -> 排名(从1开始)
        //离散化 只留关系不留数值 所以可以直接替换
        //要离散化是因为fa数组要开很大 优化的是这个数组
        sort(d.begin(),d.end());//unique只能处理相邻重复
        d.erase(unique(d.begin(),d.end()),d.end());
        auto get_id=[&](int val){
            return lower_bound(d.begin(),d.end(),val)-d.begin()+1;//返给并查集的下标
        };

        init(d.size());
        for(int i=0;i<n;i++)
            if(v[i].e==1)unite(get_id(v[i].l),get_id(v[i].r));
        bool ok=true;
        for(int i=0;i<n;i++)
            if(v[i].e==0 && same(get_id(v[i].l),get_id(v[i].r))){
                ok=false;
                break;
            }

        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}

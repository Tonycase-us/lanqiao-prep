 #include<iostream>
#include<vector>
#include<queue>
#include<numeric>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

struct Dijkstra {
    static const int INF = 1E18;
    int n;
    vector<vector<pair<int, int>>> ver;
    vector<int> dis, vis;
    Dijkstra(int n) {
        this->n = n;
        ver.resize(n + 1);
        dis.resize(n + 1);
        vis.resize(n + 1);
    }
    void add(int x, int y, int w) { // 如果是无向图，再补一条 add(y, x, w)
        ver[x].push_back({y, w});
    }
    void init() {
        fill(dis.begin(), dis.end(), INF);
        fill(vis.begin(), vis.end(), 0);
    }
    void work(int s = 1) {
        init();
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.emplace(0, s);
        dis[s] = 0;
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (auto [y, w] : ver[x]) {
                if (dis[y] > dis[x] + w) {
                    dis[y] = dis[x] + w;
                    q.emplace(dis[y], y);
                }
            }
        }
    }
    int getDis(int x) {
        return dis[x];
    }
};

struct DSU {
    vector<int> fa, p, e, f;

    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        p.resize(n + 1, 1);
        e.resize(n + 1);
        f.resize(n + 1);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) { // 设x是y的祖先
        if (x == y) f[get(x)] = 1;
        x = get(x), y = get(y);
        e[x]++;
        if (x == y) return false;
        if (x < y) swap(x, y); // 将编号小的合并到大的上
        fa[y] = x;
        f[x] |= f[y], p[x] += p[y], e[x] += e[y];
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    bool F(int x) { // 判断连通块内是否存在自环
        return f[get(x)];
    }
    int size(int x) { // 输出连通块中点的数量
        return p[get(x)];
    }
    int E(int x) { // 输出连通块中边的数量
        return e[get(x)];
    }
};

struct node{
    int id,val;
    node()=default;
    node(int ID,int VAL){id=ID,val=VAL;}
    bool operator<(const node &x) const{return val<x.val;}
};

vector<int> vec[200005];
int d[200005];
void slove(){
    int n,m,a,b,s,t;
    cin>>n>>m>>a>>b>>s>>t;
    Dijkstra dij_a(n),dij_b(n);
    DSU dsu(n);
    for(int i=1;i<=m;i++){
        int p1,p2;
        cin>>p1>>p2;
        vec[p1].push_back(p2);
        vec[p2].push_back(p1);
        dij_a.add(p1,p2,1);
        dij_a.add(p2,p1,1);
        dij_b.add(p1,p2,1);
        dij_b.add(p2,p1,1);
    }
    dij_a.init();
    dij_b.init();
    dij_a.work(a);
    dij_b.work(b);
    vector<node> pv;
    for(int i=1;i<=n;i++){
        d[i]=abs(dij_a.getDis(i)-dij_b.getDis(i));
        pv.push_back(node(i,d[i])); 
    }
    sort(pv.begin(),pv.end());
    int ans=max(d[s],d[t]);
    for(int i=0;i<n;i++){
        if(dsu.same(s,t)){cout<<ans;return ;}
        for(int j:vec[pv[i].id]){
            if(d[j]<=d[pv[i].id])dsu.merge(pv[i].id,j);
        }
        ans=max(ans,pv[i].val);
    }
    cout<<ans;
}
signed main(){
    slove();
}
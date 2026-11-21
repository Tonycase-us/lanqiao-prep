#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,h;
const int MAX=200005;
int p[MAX],a[MAX],f[MAX];
void s(){//前缀和
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
}

void u(int l,int r,int v){//差分左边
    a[l]+=v;
    a[l+1]-=v-1;
    a[r+1]-=v+(r-l+1);
    a[r+2]+=v+(r-l+1)-1;
}
void d(int l,int r,int v){//差分右边
    a[l]+=v;
    a[l+1]-=v+1;
    a[r+1]-=v-(r-l+1);
    a[r+2]+=v-(r-l+1)+1;
}

void solve(){
    cin>>n>>m>>h;
    for(int i=1;i<=m;i++)cin>>p[i]>>f[i];
    int ans=-1,l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1;i<=mid;i++){
            int cut=max(f[i]-p[i],0LL);
            u(max(p[i]-f[i]+1,1LL),p[i],1+cut);
            d(p[i]+1,min(p[i]+f[i]-1,n),f[i]-1);
        }
        s();s();
        int mx=0;
        for(int i=1;i<=n;i++)mx=max(mx,a[i]);
        if(mx>h){
            ans=mid;r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(ans==-1)cout<<"No"<<'\n';
    else cout<<"Yes"<<'\n'<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
   // cin >> T;
    while(T--){
        solve();
    }
}

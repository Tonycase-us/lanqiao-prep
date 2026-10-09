#include<iostream>
#include<vector>
#include<unordered_map>
#define int long long
using namespace std;
int search_index(int *v,int m){
    int min_index=0;
    int min=v[0];
    for(int i=1;i<m;i++){
        if(min>v[i]){
            min=v[i];
            min_index=i;
        }
    }
    return min_index;
}
signed main(){
    int n;cin>>n;
    while(n--){
        int m,k;cin>>m>>k;
        int v[200005][4];
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            v[i][0]=a+b+c;
            v[i][1]=a-b;
            v[i][2]=a-c;
            v[i][3]=b-c;
        }
        int index=search_index(*v,m);
        
    }
}
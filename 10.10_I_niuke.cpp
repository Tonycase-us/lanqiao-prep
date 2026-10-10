//回忆了一下图 仅此而已
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
#define int long long
int dir[4][2]={1,0,-1,0,0,1,0,-1};
bool find_1=false;
bool find_2=false;
void dfs(vector<vector<int>>&visted,vector<vector<int>>&grapth,int i,int j,int n,int r1,int r2,int c1,int c2){
    if(j>n||j<1||i>2||i<1)return ;
    if(visted[i][j]||grapth[i][j])return ;
    visted[i][j]=1;
    if(i==r1&&j==r2)find_1=true;
    if(i==c1&&j==c2)find_2=true;
    for(int k=0;k<4;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            dfs(visted,grapth,ni,nj,n,r1,r2,c1,c2);
    }
}
signed main(){
    int n;cin>>n;
    vector<vector<int>>visted(3,vector<int>(n+1,0));
    vector<vector<int>>grapth(3,vector<int>(n+1,0));
    int r1,r2,c1,c2;
    cin>>r1>>r2>>c1>>c2;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            cin>>grapth[i][j];
        }
    }
    find_1=false;
    find_2=false;
    dfs(visted,grapth,1,1,n,r1,r2,c1,c2);
    if(find_1&&find_2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
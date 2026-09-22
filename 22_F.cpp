/*
二维滑动窗口
up向下压缩 删掉上面的元素 去掉他的前缀和  
*/
#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    int res=0;
    vector<vector<int>>math(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>math[i][j];
        }
    }
    for(int up=1;up<=n;up++){
        vector<int>b(m+1,0);
        for(int down=up;down<=n;down++){
        for(int j=1;j<=m;j++){
            b[j]+=math[down][j];
        }
        int sum=0;
        int left=1;
        for(int right=1;right<=m;right++){
            sum+=b[right];
            while(sum>k&&left<=right){
                sum-=b[left++];
            }
            res+=(right-left+1);
        }
    }
    }
    cout<<res;
}
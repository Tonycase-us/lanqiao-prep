/*前缀和 用了kadane算法 动态规划的入门
第一个有思路的普及题 纪念一下 
*/
#include<iostream>
#include<vector>
using namespace std;
#define int long long
int ans[120][120];
int num[120]={0};
signed main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ans[i][j];
        }
    }
    int res=ans[0][0];
    for(int up=0;up<n;up++){
        int max_num;
        for(int i=0;i<120;i++)num[i]=0;
        for(int down=up;down<n;down++){
            for(int i=0;i<n;i++){
                num[i]+=ans[down][i];
            }
            max_num=num[0];
            int best=num[0];
            for(int i=1;i<n;i++){
                max_num=max(max_num+num[i],num[i]);
                best=max(best,max_num);
            }
            res=max(res,best);
        }
       
    }
    cout<<res;
}
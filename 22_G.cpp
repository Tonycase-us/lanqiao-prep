//这个题用long long会超空间 用原味int
//第一次在洛谷遇到dp 认出来了 但是做出来还是要差太多
//dp数组定义为 dp[i][0]第i列积木块是正好平的 dp[i][1]是上面缺一个 dp[i][2]是下面缺一个
#include<iostream>
#include<vector>
using namespace std;
//#define int long long
const int mod=1000000007;
const int MAX=10000000+100;
int dp[MAX][3]={0};
int add(int a,int b){
    a+=b;
    if(a>=mod){
        a=a-mod;
    }
    return a;
}
signed main(){
    int n;cin>>n;
   // vector<vector<int>>dp(n+1,vector<int>(3,0));
    dp[1][0]=1;
    dp[1][1]=0;
    dp[1][2]=0;
    dp[2][0]=2;
    dp[2][1]=1;
    dp[2][2]=1;
    for(int i=3;i<=n;i++){
        dp[i][0]=add(add(dp[i-1][0],dp[i-2][0]),add(dp[i-1][1],dp[i-1][2]));
        dp[i][1]=add(dp[i-1][2],dp[i-2][0]);
        dp[i][2]=add(dp[i-1][1],dp[i-2][0]);
    }
    cout<<dp[n][0];
}
/*但是那个题说的太勉强了 应该使用滚动数组!!! dp定义为4行3列的 那么这个四
正好是存储三个元素 加一个空位留给缓冲(这个先记住 用n个元素就用n+1的空间)
vector<vector<int>> dp(4, vector<int>(3, 0));   // 或者 int dp[4][3];

dp[1 % 4][0] = 1;
dp[2 % 4][0] = 2; dp[2 % 4][1] = 1; dp[2 % 4][2] = 1;

for (int i = 3; i <= n; i++) {
    int a = i % 4, b = (i - 1) % 4, c = (i - 2) % 4;
    dp[a][0] = add(add(dp[b][0], dp[c][0]), add(dp[b][1], dp[b][2]));
    dp[a][1] = add(dp[b][2], dp[c][0]);
    dp[a][2] = add(dp[b][1], dp[c][0]);
}
cout << dp[n % 4][0];
用个例子方便我理解
*/
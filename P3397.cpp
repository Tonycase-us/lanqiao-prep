//差分数组解决的经典问题 是前缀和的逆运算
//二维差分数组 定义时减上方减左方 加左上 而求前缀和时 加左 加上 减左上
//右对角线减去左对角线
#include<iostream>
#include<cmath>
using namespace std;
#define int long long
int arr[1005][1005];
signed main(){
   int n,m;cin>>n>>m;
    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        arr[x1][y1]++;
        arr[x2+1][y1]--;
        arr[x1][y2+1]--;
        arr[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
//板子
/*#include<iostream>
using namespace std;
#define int long long
int d[1005][1005];   // 差分数组，记得开 n+2 大小

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, q;      // n 行 m 列，q 次矩形加
    cin >> n >> m >> q;
    // 若初始矩阵非零，读入时直接算差分
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int a; cin >> a;
            d[i][j] += a;
            d[i+1][j] -= a;
            d[i][j+1] -= a;
            d[i+1][j+1] += a;    // 等价于把单点 a 当成 1×1 矩形加
        }

    while (q--) {
        int x1, y1, x2, y2, z;
        cin >> x1 >> y1 >> x2 >> y2 >> z;
        d[x1][y1] += z;
        d[x2+1][y1] -= z;
        d[x1][y2+1] -= z;
        d[x2+1][y2+1] += z;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];   // 原地求二维前缀和
            cout << d[i][j] << " \n"[j == m];
        }
    }
}
*/

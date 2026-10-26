#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<string>
using namespace std;
#define int long long
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int>left(n+1,0);
        vector<int>right(m+1,0);
        int sum_left=0;
        int sum_right=0;
        for(int i=0;i<n;i++){
            cin>>left[i];
            sum_left+=left[i];
        }
        sort(left.begin(),left.end(),greater<int>());
        for(int i=0;i<m;i++){
            cin>>right[i];
            sum_right+=right[i];
        }
        sort(right.begin(),right.end(),greater<int>());
        int cnt=0;
        if(sum_left==sum_right){cnt=1;}
        else{
            int index=0;
            if(sum_left>sum_right){
                while(sum_left>sum_right){
                sum_left-=left[index];
                    cnt++;
                    index++;
                    }
            }
            else{
                while(sum_left<sum_right){
                    sum_right-=right[index];
                    cnt++;
                    index++;
                }
            }
        }
        cout<<cnt<<'\n';
}
}

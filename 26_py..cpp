/*错误的第一个点 字符串定义的在两个循环外 会swap交换使值错误 
用 skip表示只能跳一次 如果匹配成功 短串必多跳
*/
#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    int ans=0;
    vector<string>str(n);
    for(int i=0;i<n;i++)cin>>str[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string s1=str[i];
            string s2=str[j];
            if(s1.size()<s2.size()){swap(s1,s2);}//s1是长串
            if(s1.size()-s2.size()!=1)continue;
            int fast=0;int slow=0;
            bool skip=false;
            bool ok=true;
            while(slow<s2.size()){
                if(s1[fast]==s2[slow]){slow++;fast++;}
                else{
                    if(skip){ok=false;break;}
                    else{
                        skip=true;
                        fast++;
                    }
                }
            }
            if(ok){
                ans++;
            }
        }
    }
    cout<<ans*2;
}
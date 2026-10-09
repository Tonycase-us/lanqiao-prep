//(a&b)+(a|b)=a+b
//转化为两数之和
/*  链接：https://ac.nowcoder.com/acm/contest/141374/C
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        unordered_map<int,int>map;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>> v[i];
        bool f=false;
        for(int i=0;i<n;i++){
            auto it=map.find(target-v[i]);
            if(it!=map.end()){
                cout<<it->second+1<<" "<<i+1<<endl;
                f=true;
                break;
            }
            else{
                map.insert(pair<int,int>(v[i],i));
            }
        }
        if(!f){cout<<-1<<endl;}
    }
}
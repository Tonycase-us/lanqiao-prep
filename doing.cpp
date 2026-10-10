#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
#define int long long
signed main(){
    int x,y;
    cin>>x>>y;
    int ans=0;
    for(int k=0;k<=y;k++){
        int h=x+y*k;
        int l=1;
        int r=2e5;
        while(l<=r){
            int mid=(l+r)/2;
            int num=(mid+1)*mid/2;
            if(num>=h){r=mid-1;}
            else{l=mid+1;}
        }
        ans=max(ans,l-k);
    }
    cout<<ans;
}
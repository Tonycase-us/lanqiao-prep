#include<iostream>
using namespace std;
int main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    if(n==1)cout<<"YES"<<endl<<1<<endl;
    else if(n==3)cout<<"YES"<<endl<<1<<" "<<2<<" "<<"3"<<endl; 
    else cout<<"NO"<<endl;   
  }
}
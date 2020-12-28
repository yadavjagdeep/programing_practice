#include<iostream>
#include<vector>
#include<cstdbool>
#define ll long int
using namespace std;
int main(){
  int t;cin>>t;
  while (t--) {
    ll n,k;
    cin>>n>>k;
    bool flag = false;
    std::vector<ll> v;
    for(int i=0;i<n;i++){
      ll val;cin>>val;
      v.push_back(val);
    }
    int p1=0;
    int p2=0;
    ll sum=v[0];
    while(p1<=n-1 && p2<=n-1){
      if(sum==k){
        cout<<p1+1<<" "<<p2+1<<endl;
        flag=true;
        break;
      }else if(sum<k){
        p2++;
        sum+=v[p2];
      }else{
        sum-=v[p1];
        p1++;
      }
    }
    if(!flag)
    cout<<-1<<endl;
  }
return 0;
}

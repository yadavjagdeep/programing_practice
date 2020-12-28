#include<iostream>
#include<vector>
#define ll long int
using namespace std;
ll missing(vector<ll>&v){
  ll l=0,h=v.size()-1;

  while (h-l>1) {
    ll m = ((l+h)/2);
    if((v[m]-m)==1)
    l=m;
    else if(v[m]-m ==2)
    h=m;
  }
  return v[h]-1;
}
int main(){
  int t;cin>>t;
  while (t--) {
    ll n;cin>>n;
    std::vector<ll> v;
    for(int i=0;i<n-1;i++){
      ll val;cin>>val;
      v.push_back(val);
    }
    if(n==2){
      if(v[0]==1)
      cout<<2<<endl;
      else
      cout<<1<<endl;
    }else
    cout<<missing(v)<<endl;
    v.clear();
  }
return 0;
}

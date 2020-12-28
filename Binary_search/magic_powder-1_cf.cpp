//Actually this is solution of magic powder-2
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll key;
bool is_valid(ll m,vector<ll>v,vector<ll>a){
  //cout<<key<<" "<<m<<endl;
  ll k=key;
  ll n = v.size();
  for(ll i=0;i<n;i++){
    if((v[i]*m)>a[i]){
      if((v[i]*m)>(a[i]+k)){
        //cout<<m<<" "<<v[i]<<endl;
        return false;
      }else{
        k = ((a[i]+k)-(v[i]*m));
      }
    }
  }
return true;
}
ll binary_search(vector<ll>&v,vector<ll>&a){
  //int mx = *max_element(a.begin(),a.end());
  /*int mx=0;
  for(int i=0;i<v.size();i++){
    mx = max(mx,a[i]/v[i]);
  }*/
//  cout<<mx<<endl;
  ll l=0,h=INT_MAX;
  while((h-l)>1){
    ll m = l+((h-l)/2);
    if(is_valid(m,v,a))
    l=m;
    else
    h=m;
  }
return l;
}
int main(){
  ll n;
  cin>>n>>key;
  std::vector<ll> v;
  for(ll i=0;i<n;i++){
    ll val;cin>>val;
    v.push_back(val);
  }
  std::vector<ll>a;
  for(ll i=0;i<n;i++){
    ll val;cin>>val;
    a.push_back(val);
  }
  cout<<binary_search(v,a)<<'\n';
return 0;
}

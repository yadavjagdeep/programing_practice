#include<iostream>
#include<vector>
#define ll long long
using namespace std;
ll floor(vector<ll>&v,ll k){
  ll n = v.size();
  ll low=0;
  ll high = n-1;
  ll ans=-1;
  while (low<=high) {
    ll mid = low+(high-low)/2;
    if(v[mid]==k)
    return v[mid];
    else if(v[mid]<k){
      ans = v[mid];
      low = mid+1;
    }else
    high = mid-1;
  }
  return ans;
}
/*ll floor(vector<ll>&v,ll k){
  ll n = v.size();
  ll low = 0;
  ll high = n-1;
  while (high-low>1) {
    ll mid = low+(high-low)/2;
    if(v[mid]==k)
    return v[mid];
    else if(v[mid]<k)
    low = mid;
    else
    high = mid-1;
  }
  if(v[low]<k)
  return v[low];
return -1;
}*/
int main(){
  int t;cin>>t;
  while (t--) {
    ll n;cin>>n;
    ll k;cin>>k;
    std::vector<ll> v;
    for(ll i=0;i<n;i++){
      ll val;cin>>val;
      v.push_back(val);
    }
    cout<<floor(v,k)<<endl;
  }
return 0;
}

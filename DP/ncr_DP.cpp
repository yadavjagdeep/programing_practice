//since C(n,r) = C(n-1,r-1)+C(n-1,r)
#include<iostream>
#include<vector>
#include<cstring>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[1005][1005];
ll Binomialcoff(ll n,ll r){
  if(n<=0)
  return 0;
  if(r==0 || r==n)
  return 1;
  if(dp[n][r]!=-1)
  return dp[n][r];
  return dp[n][r] = (Binomialcoff(n-1,r-1)%mod +Binomialcoff(n-1,r)%mod)%mod;
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    ll n;cin>>n;
    ll r;cin>>r;
    cout<<Binomialcoff(n,r)<<endl;
  }
return 0;
}

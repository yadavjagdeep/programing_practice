#include<iostream>
#include<cstring>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[102];
ll lucas(ll n){
  if(n==0)
  return 2;
  if(n==1)
  return 1;
  if(dp[n]!=-1)
  return dp[n]%mod;
  return dp[n]=(lucas(n-1)%mod+lucas(n-2)%mod)%mod;
}
int main(){
  memset(dp,-1,sizeof(dp));
  dp[0]=2;
  dp[1]=1;
  lucas(101);
  int t;cin>>t;
  while (t--) {
    ll n;cin>>n;
    cout<<dp[n]<<endl;
  }
return 0;
}

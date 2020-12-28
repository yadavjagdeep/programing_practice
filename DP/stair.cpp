#include<iostream>
#include<cstring>
#include<cstdio>
#define mod 1000000007
#define ll long long int
using namespace std;
long long int dp[100001]={0};
ll ways(ll n){
  if(n==0 || n==1)
  return 1;
  if(dp[n]!=0)
  return dp[n];
  return dp[n] = ways(n-1)+ways(n-2);
}
int main(){
  ll t;cin>>t;
  dp[0]=1;
  dp[1]=1;
  ways(100000);
  for(int i=0;i<20;i++)
  cout<<dp[i]<<" ";
  while (t--) {
    ll n;cin>>n;
    cout<<dp[n]<<endl;
  }
return 0;
}

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[100001];
int fn(int n){
  if(n==0)
  return 0;
  if(dp[n]!=-1)
  return dp[n];
  int x = fn(n/2);
  int y = fn(n/3);
  int z = fn(n/4);
  return dp[n] = max(n,(x+y+z));
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    cout<<max(n,fn(n))<<endl;
  }
return 0;
}

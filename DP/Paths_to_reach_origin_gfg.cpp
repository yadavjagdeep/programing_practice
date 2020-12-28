#include<iostream>
#include<cstring>
using namespace std;
int dp[26][26];
int ways(int n,int m){
  if(n<0 || m<0)
  return 0;
  if(n==0 && m==0)
  return 1;
   if(dp[n][m]!=-1)
   return dp[n][m];
  return dp[n][m]=ways(n-1,m)+ways(n,m-1);
}
int main(){
  int t;cin>>t;
  while (t--) {
      memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    cout<<ways(n,m)<<endl;
  }
return 0;
}

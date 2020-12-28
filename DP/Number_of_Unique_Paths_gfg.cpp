#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
int dp[21][21];
int ways(int i,int j){
  if(i==n || j==m)
  return 0;
  if(i==n-1 && j==m-1)
  return 1;
   if(dp[i][j]!=-1)
   return dp[i][j];
  return dp[i][j] = (ways(i+1,j)+ways(i,j+1));
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cout<<ways(0,0)<<endl;
  }
return 0;
}

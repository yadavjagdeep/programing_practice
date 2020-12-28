#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int dp[11][51];
int solve(int e,int f){
  if(f==1 || f ==0)return 1;
  if(e==1)return f;
  if(dp[e][f]!=-1)
  return dp[e][f];
  int ans = INT_MAX;
  for(int k=1;k<=f;k++){
    ans = min(ans,1+max(solve(e-1,k-1),solve(e,f-k)));
  }
return dp[e][f]=ans;
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    int e;cin>>e;
    int f;cin>>f;
    cout<<solve(e,f)<<endl;
  }
return 0;
}

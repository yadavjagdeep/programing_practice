#include<iostream>
#include<cstring>
using namespace std;
  int n;
  int dp[10001];
int mop(int x){
  if(x==n)
  return 1;
  if(x>n)
  return 20;
  if(dp[x]!=-1)
  return dp[x];
  if(dp[x]!=-1)
  return dp[x];
  int ans1 = mop(x+1);
  int ans2 = mop(x*2);
  if(ans1 !=0 && ans2 !=0)
  return  dp[x] = 1+min(ans1,ans2);
  else if(ans1!=0)
  return dp[x]= 1+ans1;
  else if(ans2!=0)
  return dp[x] = 1+ans2;
}
int main(){

  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    cin>>n;
      cout<<mop(1)<<endl;
  }
return 0;
}

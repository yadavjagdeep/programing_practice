#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
int dp[4001];
  int x,y,z;
int seg(int t){
  if(t==0)
  return dp[t] = 0;
  if(t<0)
  return dp[t] = INT_MIN;
  if(dp[t]!=-1)
  return dp[t];
   return dp[t] = max(seg(t-x),max(seg(t-y),seg(t-z)))+1;
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
memset(dp,-1,sizeof(dp));
    cin>>x>>y>>z;
    int ans = seg(n);
    if(ans>0)
    cout<<ans<<endl;
    else
    cout<<0<<endl;
    //cout<<seg(n)<<endl;
  }
return 0;
}

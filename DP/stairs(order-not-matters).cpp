#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
long long dp[1000001][3];
int n;
int ways(int s,int x){
  if(x>2)
  return 0;
  if(s==n)
  return 1;
  if(s>n)
  return 0;
   if(dp[s][x]!=-1)
   return dp[s][x];
return dp[s][x]=(ways(s+x,x)+ways(s,x+1));

}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<ways(0,1)<<endl;
  }
return 0;
}

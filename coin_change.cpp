#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[350][350];
int ways(int i,int s,int n,int c[],int amt){
  if(i>n-1)
  return 0;
  if(s>amt)
  return 0;
  if(s==amt)
  return 1;
  if(dp[i][s]!=-1)
  return dp[i][s];
  //int res;
  for(int y=0;y<n;y++){
     return dp[i][s] = ways(i,s+c[i],n,c,amt)+ways(i+1,s,n,c,amt);
  }
//return res;
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    int c[n];
    for(int i=0;i<n;i++){
      cin>>c[i];
    }
    int amt;cin>>amt;
    memset(dp,-1,sizeof(dp));
    cout<<ways(0,0,n,c,amt)<<endl;
  }
return 0;
}

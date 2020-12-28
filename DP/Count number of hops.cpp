#include<iostream>
#include<cstdio>
using namespace std;
int dp[55]={0};
int ways(int n){
  if(n==1)
  return 1;
  if(n==2)
  return 2;
  if(n==3)
  return 4;
  if(dp[n]!=0)
  return dp[n];
  return dp[n]=ways(n-1)+ways(n-2)+ways(n-3);
}
int main(){
  int t;cin>>t;
  dp[1]=1;
  dp[2]=2;
  dp[3]=4;
  ways(51);
  while (t--) {
    int n;cin>>n;
    cout<<dp[n]<<endl;
  }
return 0;
}

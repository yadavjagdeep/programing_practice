#include<iostream>
#include<cstdio>
#include<cstdbool>
#include<cstring>
using namespace std;
int dp[30003];
int ways(int i,int a[],int n){
  if(i>=n-1)
  return 1;
  if(a[i]==0)
  return 0;
if(dp[i]!=-1)
return dp[i];
  int  sum=0;
  for(int y=1;y<=a[i];y++)
   sum+=ways(i+y,a,n);
   dp[i]=sum;
return sum;

}
int main(){
  int n;cin>>n;
  memset(dp,-1,sizeof(dp));
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  cout<<ways(0,a,n)<<endl;
  return 0;
}

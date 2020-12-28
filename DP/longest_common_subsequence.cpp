#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1001][1001];
int lcs(string s1,string s2,int i,int j ){
  if(i==-1 || j==-1)
  return 0;
  if(dp[i][j]!=-1)
  return dp[i][j];
  if(s1[i]==s2[j])
  return dp[i][j] = 1+lcs(s1,s2,i-1,j-1);
  return dp[i][j] = max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
}
int main(){
  string s1;cin>>s1;
  string s2;cin>>s2;
  memset(dp,-1,sizeof(dp));
  cout<<lcs(s1,s2,s1.size()-1,s2.size()-1)<<endl;
  return 0;
}

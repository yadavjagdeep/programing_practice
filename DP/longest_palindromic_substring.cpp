// can be solved by taking reverse of given string and then lcs of them
#include<iostream>
#include<cstring>
using namespace std;
int dp[1000][1000];
int lps(int i,int j,string s){
  if(i==j)
  return 1;
  if(i>j)
  return 0;
  if(dp[i][j]!=-1)
  return dp[i][j];
  if(s[i]==s[j])
  return dp[i][j]=2+lps(i+1,j-1,s);
  return dp[i][j]=max(lps(i+1,j,s),lps(i,j-1,s));
return 0;
}
int main(){
  string s;cin>>s;
  memset(dp,-1,sizeof(dp));
  cout<<lps(0,s.size()-1,s)<<endl;
return 0;
}

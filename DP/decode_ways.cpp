#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string s;
int n;
int dp[10000];
int ways(int i){
  if(i==n)
  return 1;
  if(s[i]=='0')
  return 0;
  if(dp[i]!=-1)
  return dp[i];
  string str = s.substr(i,2);
  int x = stoi(str);
  if(i==n-1 || x>26)
  return dp[i] = ways(i+1);
  else
  return dp[i] = ways(i+1)+ways(i+2);
}
int main(){
  memset(dp,-1,sizeof(dp));
  cin>>s;
  n = s.size();
  cout<<ways(0)<<endl;
return 0;
}

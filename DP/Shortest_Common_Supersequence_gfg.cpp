#include<iostream>
#include<cstring>
using namespace std;
string s1,s2;
int dp[101][101];
int LCS(int i,int j){
  if(i==s1.size()||j == s2.size())
  return 0;
  if(dp[i][j]!=-1)
  return dp[i][j];
  if(s1[i]==s2[j])
  return dp[i][j]=1+LCS(i+1,j+1);

  return dp[i][j]=max(LCS(i+1,j),LCS(i,j+1));
}
int main(){

  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    int x = LCS(0,0);
    int a = s1.size();
    a-=x;
    int b = s2.size();
    b-=x;
    cout<<a+b+x<<endl;
  }
return 0;
}

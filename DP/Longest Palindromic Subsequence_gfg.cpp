#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lps(const string &str,int i,int j){
  if(j<i)
  return 0;
  else if(i==j)
  return 1;
  if(dp[i][j]!=-1)
  return dp[i][j];
  else if(str[i]==str[j])
  return dp[i][j]=2+lps(str,i+1,j-1);
  else return dp[i][j]=max(lps(str,i+1,j),lps(str,i,j-1));
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    string str;cin>>str;
    cout<<lps(str,0,str.size()-1)<<endl;
  }
return 0;
}

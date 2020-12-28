#include<iostream>
#include<vector>
#include<cstdbool>
#include <algorithm>
#include<cstring>
using namespace std;
bool cmp(int a, int b)
{
    return (a < b);
}
int dp[101][101];
int n,m;
string s1,s2;
int op(int i,int j){
  if(i>=n)
  return m-j;
  if(j>=m)
  return n-i;
  if(dp[i][j]!=-1)
  return dp[i][j];
  if(s1[i] == s2[j])
  return dp[i][j]= op(i+1,j+1);
 return dp[i][j] = std::min(std::min(op(i,j+1)+1,op(i+1,j)+1), op(i+1,j+1)+1);
//  return min({op(i,j+1)+1,op(i+1,j)+1,op(i+1,j+1)+1},cmp);
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cin>>s1>>s2;
    dp[n][0] = m;
    dp[0][m] = n;
    cout<<op(0,0)<<endl;
  }

return 0;
}

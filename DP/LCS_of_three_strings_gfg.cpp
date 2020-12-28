#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[101][101][101];
  int n,m,k;
  string str1;
  string str2;
  string str3;
  int LCS(int x,int y,int z){
    if(x==n || y==m || z==k)
    return 0;
    if(dp[x][y][z]!=-1)
    return dp[x][y][z];
    if((str1[x] == str2[y])&&(str2[y] == str3[z]))
    return dp[x][y][z]=1+LCS(x+1,y+1,z+1);
    else
    return dp[x][y][z]=max({LCS(x+1,y,z),LCS(x,y+1,z),LCS(x,y,z+1)});
  }
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    cin>>str1>>str2>>str3;
    cout<<LCS(0,0,0)<<endl;
  }
return 0;
}

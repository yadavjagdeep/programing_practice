#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
int dp[21][21];
  int n;
    vector<vector<int>> v;


int path(int i,int j){
  if(i<0 || j<0)
  return INT_MIN;
  if(i>n-1 || j>n-1)
  return INT_MIN;
  if(i==n-1)
  return dp[i][j]=v[i][j];
if(dp[i][j]!=-1)
return dp[i][j];
  return dp[i][j]=max({path(i+1,j),path(i+1,j-1),path(i+1,j+1)})+v[i][j];
}
int main(){
  int t;cin>>t;
  while (t--) {
memset(dp,-1,sizeof(dp));
  cin>>n;
    for(int i=0;i<n;i++){
      vector<int>row;
      for(int j=0;j<n;j++){
        int val;cin>>val;
        row.push_back(val);
      }
      v.push_back(row);
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
      ans = max(ans,path(0,i));
    }
    cout<<ans<<endl;
    v.clear();
  }
return 0;
}

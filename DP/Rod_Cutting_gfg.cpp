#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;
int dp[101][101];
std::vector<int> v;
int n;
int maxprofit(int i,int l){
  if(l>n)
  return INT_MIN;
  if(l==n)
  return 0;
    int ans = INT_MIN;
  if(dp[i][l]!=-1)
   return dp[i][l];
  for(int y=0;y<n;y++){
    ans = max(ans,maxprofit(y,l+y+1)+v[y]);
  }
return dp[i][l]=ans;
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    v.clear();
    cin>>n;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    cout<<maxprofit(0,0)<<endl;
  }
return 0;
}

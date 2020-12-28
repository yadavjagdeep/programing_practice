#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
int dp[1000000];
std::vector<int> v;
int ls(int x){
  if(x==v.size()-1)
  return dp[x] = v[x];
  if(dp[x]!=-1)
  return dp[x];
  int ans = v[x];
  for(int i=x+1;i<v.size();i++){
    if(v[i]>v[x]){
      ans = max(ans,ls(i)+v[x]);
    }
  }
return dp[x] = ans;
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    v.clear();
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
      ans = max(ans,ls(i));
    //cout<<ls(i)<<endl;
    }
    cout<<ans<<endl;
  }
return 0;
}

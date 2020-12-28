#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
int n,k;
std::vector<int> v;
int dp[1001][1001];
int ss(int i,int sum){
  if(sum>k)
  return 0;
  if(sum == k)
  return 1;
  if(i==n)
  return 0;
if(dp[i][sum]!=-1)
return dp[i][sum];
  return dp[i][sum] = (ss(i+1,sum+v[i])+ss(i+1,sum));

}
using namespace std;
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
    cin>>k;
    cout<<ss(0,0)<<endl;
  }
return 0;
}

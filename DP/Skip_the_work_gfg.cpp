#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[31][10001][2];
int n;
std::vector<int> v;
int work(int i,int sum,int f){
  if(i>=n)
  return sum;
  if(dp[i][sum][f]!=-1)
  return dp[i][sum][f];
  if(f==0){
    return dp[i][sum][f]=min(work(i+1,sum+v[i],0),work(i+1,sum,1));
  }else{
    return dp[i][sum][f]=work(i+1,sum+v[i],0);
  }
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
    cout<<work(0,0,0)<<endl;
  }
return 0;
}

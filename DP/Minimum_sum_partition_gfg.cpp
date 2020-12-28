#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
std::vector<int> v;
int dp[51][40001];
bool ss(int i,int sum,int n){
  if(sum==n)
  return true;
  if(sum>n)
  return false;
  if(i>=v.size())
  return false;
  if(dp[i][sum]!=-1)
  return dp[i][sum];

  return dp[i][sum]= ss(i+1,sum+v[i],n)||ss(i+1,sum,n);
}
int main(){
  int t;cin>>t;
  while (t--) {
    v.clear();

    int n;cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
      sum+=val;
    }
    int x = sum/2;
    bool flag = false;
    while (!flag) {
        memset(dp,-1,sizeof(dp));
      if(ss(0,0,x)){
        flag = true;
        break;
      }
      x= x-1;
    }
    int x1 = sum-x;

    cout<<x1-x<<endl;
  }
return 0;
}

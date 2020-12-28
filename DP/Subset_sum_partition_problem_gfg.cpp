#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[101][10000];
  std::vector<int> v;
  bool subsetsum(int i,int sum,int n){
    if(sum==n)
    return true;
    if(sum>n)
    return false;
    if(i>=v.size())
    return false;
if(dp[i][sum]!=-1)
return true;
    return dp[i][sum]=subsetsum(i+1,sum+v[i],n)||subsetsum(i+1,sum,n);
  }
int main(){
  int t;cin>>t;
  while (t--) {
    v.clear();
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    long long int sum = 0;

    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
      sum+=val;
    }
    cout<<subsetsum(0,0,sum/2);
  /*  if(sum%2 == 0){
      if(subsetsum(0,0,sum/2))
      cout<<"YES"<<endl;
      else
      cout<<"NO"<<endl;
    }else{
      cout<<"NO"<<endl;
    }*/
  }
return 0;
}

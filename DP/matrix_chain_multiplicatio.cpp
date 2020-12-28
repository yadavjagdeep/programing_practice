#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 std::vector<int> v;
 long int dp[101][101];
long int op(long int x,long int y){

    if(x+1 == y)
    return 0;
    if(dp[x][y]!=-1)
    return dp[x][y];
    long int ans = 10e9;
  for(long int i=x+1;i<=y-1;i++){
 long int temp =  op(x,i)+op(i,y)+v[x]*v[i]*v[y];

  //cout<<temp<<endl;
  if(temp<ans){
      dp[x][y] = temp;
      ans = temp;
  }

//  return ans;
  }
  return ans;
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
  v.clear();
     for(int i=0;i<n;i++)
     {
       int val;cin>>val;
       v.push_back(val);
     }
     cout<<op(0,n-1)<<endl;
  }

  return 0;
}

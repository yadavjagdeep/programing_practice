#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
  std::vector<int> v;
  int dp[10000001];
int jump(int i){
  if(i>=v.size()-1)
  return 0;
  int val = 99999;
if(dp[i]!=-1)
return dp[i];

  for(int y=1;y<=v[i];y++){
    int temp = 1+jump(y+i);
       val = min(temp,val);
    //   cout<<val<<endl;


  }

return dp[i]=val;
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
  v.clear();
  memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int x = jump(0);
    if(x==99999)
    cout<<-1<<endl;
    else
    cout<<x<<endl;
  }

return 0;
}

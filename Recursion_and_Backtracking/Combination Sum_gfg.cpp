#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
int n;
void com_sum(int sum,int b,vector<vector<int>>&ans,vector<int>&temp,int k){
  if(sum==b){
    ans.push_back(temp);
    return;
  }
  for(int i=k;i<n;i++){
    if((sum+v[i])<=b){
      sum+=v[i];
      temp.push_back(v[i]);
      com_sum(sum,b,ans,temp,i);
      sum-=v[i];
      temp.pop_back();
    }
  }

}
void print(vector<vector<int>>&ans){
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<'\n';
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  int b;cin>>b;
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  vector<vector<int>>ans;
  vector<int>temp;
  com_sum(0,b,ans,temp,0);
  print(ans);

  return 0;
}

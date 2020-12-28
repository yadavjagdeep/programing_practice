#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;
vector<int> two_pointer(vector<int>&v,int x){
  int i=0,j=v.size()-1;
  vector<int>ans;
  //set<int>s;
  ans.clear();
 ans.push_back(10000);
  while (i<j) {
    if(i==x)
    i++;
    else if(j==x)
    j--;
    else if((v[i]+v[j]+v[x])==0){
      ans.pop_back();
      ans.push_back(v[i]);
      ans.push_back(v[j]);
      ans.push_back(v[x]);

      return ans;
    }else if((v[i]+v[j]+v[x])>0)
    j--;
    else
    i++;
  }
  return ans;
}
vector<vector<int>> three_sum(vector<int>&v){
  std::vector<std::vector<int>> a;
  set<vector<int>>s;
    std::vector<int> ans;
  int n = v.size();
  for(int i=0;i<n;i++){
    if(i==0 || v[i]!=v[i-1]){
      ans = two_pointer(v,i);
     if(ans[0]!=10000){
       //a.push_back(ans);
       s.insert(ans);
     }
    }

  }
  for(auto itr = s.begin();itr!=s.end();itr++){
    a.push_back(*itr);
  }
  return a;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  sort(v.begin(),v.end());
  std::vector<std::vector<int>> a=three_sum(v);;
  for(int i=0;i<a.size();i++){
    for(int j=0;j<3;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
return 0;
}

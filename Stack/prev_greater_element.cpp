#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> PSE(vector<int>&v){
  std::vector<int> a(v.size(),-1);
  stack<int>s;
  s.push(v.size()-1);
  int j=v.size()-2;
  while (j>=0) {
    if(v[j]>=v[s.top()])
    s.push(j);
    else{
      while (!s.empty() && v[s.top()]>v[j]) {
        a[s.top()] = v[j];
        s.pop();
      }
      s.push(j);
    }
    j--;
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
  std::vector<int> pse = PSE(v);
  for(auto x:pse)
  cout<<x<<" ";
return 0;
}

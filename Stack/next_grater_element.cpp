#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NGE(vector<int>&v){
  int n = v.size();
  std::vector<int> a(n,-1);
  stack<int>s;
  s.push(0);
  int j=1;
  while (j<v.size()) {
    if(v[j]<= a[s.top()])
    s.push(j);
    else{
      while (!s.empty() && v[j]>v[s.top()]) {
        a[s.top()] = v[j];
        s.pop();
      }
      s.push(j);
    }
    j++;
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
  std::vector<int>nge = NGE(v);
  for(auto x:nge)
  cout<<x<<" ";
  cout<<endl;
return 0;
}

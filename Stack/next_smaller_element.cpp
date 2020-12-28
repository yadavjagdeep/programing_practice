#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NSE(vector<int>&v){
  std::vector<int> a(v.size(),-1);
  stack<int>s;
  s.push(0);
  int j=1;
  while (j<v.size()) {
    if(v[j]>=v[s.top()])
    s.push(j);
    else{
      while (!s.empty() && v[s.top()]>v[j]) {
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
  std::vector<int> nse = NSE(v);
  for(auto x:nse)
  cout<<x<<" ";
  cout<<endl;
return 0;
}

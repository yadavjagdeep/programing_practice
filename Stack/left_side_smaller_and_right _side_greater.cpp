#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> PGE(vector<int>&v){
  std::vector<int> a;
  for(int i=0;i<v.size();i++)
  a.push_back(v[i]);
  stack<int>s;
  s.push(v.size()-1);
  int j = v.size()-2;
  while (j>=0) {
    if(v[j]<=v[s.top()])
    s.push(j);
    else{
      while (!s.empty() && v[j]>v[s.top()]) {
        a[s.top()] = v[j];
        s.pop();
      }
      s.push(j);
    }
    j--;
  }
return a;
}
//*****************************************************************************//
vector<int> NSE(vector<int>&v){
  std::vector<int> a;
  for(int i=0;i<v.size();i++)
  a.push_back(v[i]);
  stack<int>s;
  s.push(0);
  int j=1;
  while (j<v.size()) {
    if(v[j]>=v[s.top()])
    s.push(j);
    else{
      while (!s.empty() && v[j]<v[s.top()]) {
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
  int t;cin>>t;
  while (t--) {

  int n;cin>>n;
  std::vector<int> v;
  v.clear();
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  std::vector<int>a = PGE(v);
  std::vector<int>b = NSE(v);
  int ans=-1;
for(int i=1;i<n-1;i++){
  if(a[i]==b[i]){
    ans = a[i];
    break;
  }
}
cout<<ans<<endl;
  }
return 0;
}

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NGE(vector<int>&v){
  std::vector<int> a;
  for(int i=0;i<v.size();i++)
  a.push_back(v[i]);
  stack<int>s;
  s.push(0);
  int j=1;
  while (j<v.size()) {
    if(v[j]<=v[s.top()])
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
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    vector<int>leader = NGE(v);
   for(int i=0;i<v.size();i++){
     if(v[i]==leader[i])
     cout<<v[i]<<" ";
   }
  }
  cout<<endl;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  stack<int>s;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    s.push(val);
  }
  int idx = ceil(n/2);
  stack<int>a;
  int i=0;
  while(!s.empty() && i!=idx){
    a.push(s.top());
    s.pop();
    i++;
  }
  s.pop();
  while(!a.empty()){
    s.push(a.top());
    a.pop();
  }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
return 0;
}

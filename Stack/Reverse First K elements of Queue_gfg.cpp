#include<bits/stdc++.h>
using namespace std;
queue<int> reverse(queue<int>q,int n,int k){
  stack<int>s;
  for(int i=0;i<k;i++){
    s.push(q.front());
    q.pop();
  }
  queue<int>ans;
  while(!s.empty()){
    ans.push(s.top());
    s.pop();
  }
  while(!q.empty()){
    ans.push(q.front());
    q.pop();
  }
return ans;
}
int main(){
  int n,k;cin>>n>>k;
  queue<int>q;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    q.push(val);
  }
queue<int>ans=reverse(q,n,k);
while(!ans.empty()){
  cout<<ans.front()<<" ";
  ans.pop();
}
return 0;
}

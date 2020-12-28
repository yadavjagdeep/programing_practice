//we have used kadane's Algo to solve the problem
// It will work only if input is +ve integers
#include<bits/stdc++.h>
using namespace std;
int max_sum(vector<int>&v){
  int n = v.size();
  set<int>s;
  int l_max=v[0];
  int g_max=v[0];
  s.insert(v[0]);
  int i=0,j=1;
  while(i<n-1 && j<n){
    const bool is_used = s.find(v[j])!=s.end();
    if(!is_used){
      l_max = max(v[j],v[j]+l_max);
      if(l_max>g_max){
      g_max=l_max;
      }
      s.insert(v[j++]);
    }else{
    //  g_max-=v[i];
      l_max-=v[i];
      s.erase(v[i++]);
    }
  }
return g_max;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  cout<<max_sum(v)<<'\n';
return 0;
}

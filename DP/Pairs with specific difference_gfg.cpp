#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int max_diff(int x,vector<int>&v,int k){
  if(x==v.size()-2)
  return 0;
  int max=INT_MIN;
  for(int i=x+1;i<v.size();i++){
    int pairdiff = abs(v[i]-v[x]);
    if(pairdiff<k && (v[i]+v[x])>max){
      max=(v[i]+v[x]);
    }
  }
  return max+max_diff(x+1,v,k);
}
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int k;cin>>k;
    cout<<max_diff(0,v,k)<<endl;
  }
return 0;
}

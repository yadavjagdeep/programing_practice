#include<bits/stdc++.h>
using namespace std;
int binary_search(std::vector<int>&v,int key){
  int l=-1,h=v.size()-1;
  while((h-l)>1){
    int  m = ((l+h)/2);
    if(v[m]>=key)
    h=m;
    else
    l=m;
  }
return h+1;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  int m;cin>>m;
  std::vector<int>a;
  for(int i=0;i<m;i++){
    int val;cin>>val;
    a.push_back(val);
  }
  //array prefix sum of vector v;
  for(int i=1;i<n;i++){
    v[i]+=v[i-1];
  }
  //Search each warm plate using binary Search
  for(int i=0;i<m;i++){
    cout<<binary_search(v,a[i])<<"\n";
  }
return 0;
}

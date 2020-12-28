#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int min_diff(vector<int>&v,int k){
  auto x = lower_bound(v.begin(),v.end(),k);
  auto y = upper_bound(v.begin(),v.end(),k);
   int l = *x;
   int m = *y;
   int index = x - v.begin();
   if(abs(k-l)>abs(m-l))
   index = y - v.begin();
   cout<<v[index]<<endl;
  return index;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  int k;cin>>k;
  cout<<min_diff(v,k)<<endl;
return 0;
}

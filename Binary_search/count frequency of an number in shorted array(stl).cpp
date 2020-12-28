#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int frequency(vector<int>&v,int k){
  int l = distance(v.begin(),lower_bound(v.begin(),v.end(),k));
  int r = distance(v.begin(),upper_bound(v.begin(),v.end(),k));
  int ans = r-l;
  if(ans>0)
  return ans;

return -1;
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    int k;cin>>k;
    std::vector<int> v;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    cout<<frequency(v,k)<<endl;
  }
return 0;
}

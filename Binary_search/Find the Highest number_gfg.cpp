#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int highest(vector<int>&v){
  int l=1,r=v.size()-2;
  while (l<=r) {
    int m = (l+r)/2;
    if(v[m-1]<v[m] && v[m]>v[m+1]){
          return 10;
    }
    else if(v[m]>v[l])
    l = m+1;
    else
    r = m-1;
  }
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    std::vector<int> v;
    v.push_back(INT_MIN);
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    v.push_back(INT_MIN);
    cout<<highest(v)<<endl;
  }
return 0;
}

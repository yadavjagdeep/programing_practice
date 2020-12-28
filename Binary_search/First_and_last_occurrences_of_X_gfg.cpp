#include<iostream>
#include<vector>
using namespace std;
int first_occurence(vector<int>&v,int k){
  int l=0,r=v.size()-1;
  int ans = -1;
  while (l<=r) {
   int m = l+(r-l)/2;
   if(v[m]==k){
     ans = m;
     r = m-1;
   }else if(v[m]>k)
   r = m-1;
   else
   l = m+1;
  }
  return ans;
}
int last_occurence(vector<int>&v,int k){
  int l=0,r=v.size()-1;
  int ans = -1;
  while (l<=r) {
   int m = l+(r-l)/2;
   if(v[m]==k){
     ans = m;
     l = m+1;
   }else if(v[m]>k)
   r = m-1;
   else
   l = m+1;
  }
  return ans;
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
    cout<<first_occurence(v,k)<<" ";
    cout<<last_occurence(v,k)<<endl;
  }
return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>&v,int k){
  int s=0,e=v.size()-1;
  while (s<=e) {
    int m = (s+e)/2;
    if(v[m]==k)
    return m;
    else if(v[m]<k)
    s=m+1;
    else
    e=m-1;
  }
  return s;
}
int main(){
int n;cin>>n;
std::vector<int> v;
for(int i=0;i<n;i++){
  int val;cin>>val;
  v.push_back(val);
}
int k;cin>>k;
cout<<find(v,k)<<endl;
return 0;
}

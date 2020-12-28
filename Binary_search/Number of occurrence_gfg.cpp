#include<iostream>
#include<vector>
using namespace std;
int findlr(vector<int>&v,int m,int k){
  int count=0;
  for(int i=m;i<v.size();i++){
    if(v[i]==v[m])
    count++;
    else
    break;
  }
  //cout<<count<<endl;
  for(int i=m;i>=0;i--){
    if(v[i]==v[m])
    count++;
    else
    break;
  }
return count-1;
}
int occurence(vector<int>&v,int k){
  int l=0,r=v.size()-1;
  while (l<=r) {
    int m = l+(r-l)/2;
    if(v[m]==k){
      return findlr(v,m,k);
    }else if(v[m]>k)
    l = m+1;
    else
    r= m-1;
  }
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
    cout<<occurence(v,k)<<endl;
  }
return 0;
}

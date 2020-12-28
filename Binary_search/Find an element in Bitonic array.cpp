/* Find an Element in Bitonic Array
1: first we need to find peak Element
2: apply binary search to left and right of peak
*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int find_peak(vector<int>&v){
  int n = v.size();
  int low=0;
  int high = n-1;
  while (low<=high) {
    int mid = low+(high-low)/2;
    if(mid>0 && mid<n-1){
      if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
        return mid;
      }else if(v[mid+1]>v[mid]){
        low = mid+1;
      }else{
        high = mid-1;
      }
    }else if(mid==0){
      if(v[mid]>v[mid+1])
      return mid;
      else
      low = mid+1;
    }else if(mid==n-1){
      if(v[mid]>v[mid-1])
      return mid;
      else
      high = mid-1;
    }
  }
return -1;
}
//**********************************************
int lsearch(vector<int>&v,int low,int high,int k){
  while (low<=high) {
    int mid = low+(high-low)/2;
    if(v[mid]==k)
    return mid;
    else if(v[mid]>k)
    high = mid-1;
    else
    low = mid+1;
  }
return -1;
}
//**********************************************
int rsearch(vector<int>&v,int low,int high,int k){
  while (low<=high) {
    int mid = low+(high-low)/2;
    if(v[mid]==k)
    return mid;
    else if(v[mid]>k)
    low = mid+1;
    else
    high = mid-1;
  }
return -1;
}
//**********************************************
int find(vector<int>&v,int k){
  int peak = find_peak(v);
//  cout<<v[peak]<<endl;
  int l = lsearch(v,0,peak,k);
  int r = rsearch(v,peak+1,v.size()-1,k);

  //cout<<l<<" "<<r<<endl;
  if(l!=-1)
  return l;
  else if(r!=-1)
  return r;
return -1;
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

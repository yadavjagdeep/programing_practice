#include<iostream>
#include<vector>
using namespace std;
int find_k(vector<int>&v,int k,int low,int high){
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
int find_index(vector<int>&v){
  int n = v.size();
  for(int i=n-1;i>0;i--){
    if(v[i-1]>v[i])
    return i;
  }
return 0;
}
int find_element(vector<int>&v,int k){
  if(v.size()==0)
  return -1;
  if(v.size()==1)
  return (v[0]==k)? 1:-1;
  int index = find_index(v);
  int x = find_k(v,k,0,index);
  int y = find_k(v,k,index,v.size()-1);
  if(x!=-1)
  return x;
  else if(y!=-1)
  return y;
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
   int x = find_element(v,k);
   if(x==-1)
   cout<<"Not Present"<<endl;
   else
   cout<<"Present at => "<<x<<endl;
  return 0;
}

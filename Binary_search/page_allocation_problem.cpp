/* page alocation problem is one of the most important problem of binary search
## Approch to solve this problem is binary search on ans ##
1: low = max(v) and high = sum[v];
2: find mid and check if mid can be an ans
3: mid is a valid ans or not is checked by trying to divide to array such that
   sum of them should not exceed mid and if this can be done by dividing array
   in k parts then mid can be an ans
4: if mid is a valid ans we set high to mid-1 to find an ans less than mid;
*/
#include<iostream>
#include<vector>
#include<cstdbool>
using namespace std;
bool isvalid(vector<int>&v,int max,int k){
  int std = 1;
  int sum=0;
  for(int i=0;i<v.size();i++){
    sum+=v[i];
    if(sum>max){
      std++;
      sum=v[i];
    }
    if(std>k)
    return false;
  }
return true;
}
int min_pages(vector<int>&v,int k){
  if(k>v.size()) return -1;
  int n = v.size();
  int sum=0;
  int s = -1;
  for(int i=0;i<n;i++){
    sum+=v[i];
    s = max(s,v[i]);
  }

  int low = s;
  int high = sum;
  int ans=0;
  while (low<=high) {
  //  cout<<"oh yeah!!"<<endl;
    int mid = low+(high-low)/2;
     if(isvalid(v,mid,k)){
       ans = mid;
       high = mid-1;
     }else{
       low = mid+1;
     }
  }
  return ans;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  int k;cin>>k;
  cout<<min_pages(v,k)<<endl;
return 0;
}

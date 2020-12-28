/* ## find PEAK ELEMENT in an array ##
one of best question on binary search
1: just find the mid element and compare it with mid-1 and mid+1 if true return
2: if CASE 1 is not true in that case we will move to side where is greater than mid
3: we can grantee that at least 1 peak will be present at that side in worst case
   it can be last element.
*/
#include<iostream>
#include<vector>
using namespace std;
int peak(vector<int>&v){
  int n = v.size();
  int low=0;
  int high=n-1;
  while (low<=high) {

    int mid = low+(high-low)/2;
    if(mid>0 && mid<n-1){
      //cout<<"oh"<<endl;
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
    } else if(mid==n-1){
      if(v[mid]>v[mid]-1)
        return mid;
        else
        return high = mid-1;
    }

    }
  //  cout<<low<<" "<<high<<endl;
return -1;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  cout<<peak(v)<<endl;
return 0;
}

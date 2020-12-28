/*
Modified binary_search to find min_element in circularly sorted array with duplicates
1: consider as ans will be at v[end];
2: if v[mid]<v[end] => right most part is sorted => mid may be our ans => end = mid
3: if v[mid]>v[end] => we are in the part of array which is left to
    ans => start = mid+1 (mid+1 because mid cannot be our ans)
4: Most important case if v[mid]==v[end], if in case mid is min== end
    there is a chance that mid == end can be ans but to confirm it we reduce end--
    and contineu with binary_search
5: At the end our end will be at mid
*/
#include<iostream>
#include<vector>
using namespace std;
int min_ele(vector<int>&v){
  int n = v.size();
  int low=0;
  int high = n-1;
  while (low<high) {
    int mid = low+(high-low)/2;
    if(v[mid]<v[high])
    high =mid;
    else if(v[mid]>v[high])
    low = mid+1;
    else
    high--;
  }
return v[high];
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    cout<<min_ele(v)<<endl;
  }
return 0;
}

/*
Credit goes to mycodeschool
 1: needed to check if array is sorted by a[low]<=a[high] return low;
 2: next can become >= n so mid+1%n will take it to 0th index and prev can become -ve so mid+n-1 will take it to n-1
 3: if mid is less than next and prev return mid;
 4: if array[mid]<= array[high], this emplies that right half is sorted so high = m-1;
 5: if array[mid]>=a[low], this emplies that left half is sorted so low = m+1;

*/
#include<iostream>
#include<vector>
using namespace std;
int count_rotation(vector<int>&v){
  int l=0,r=v.size()-1;
  int n = v.size();
  while (l<=r) {
    int m = (l+r)/2;
    if(v[l]<=v[r])
    return l;
    int left = (m+n-1)%n;
    int right = (m+1)%n;
    if(v[m]<=v[left] && v[m]<=v[right])
    return m;
    else if(v[m]<=v[r])
    r = m-1;
    else if(v[m]>=v[l])
    l = m+1;
  }
return -1;
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
    cout<<count_rotation(v)<<endl;
  }
return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int find_k(vector<int>&v,int k){
  int low = 0; // place low and high alternate to each other
  int high = 1;
  while (v[high]<k) {  //shift high and low in such a way that k becomes enclosed by it
    low = high;
    high = 2*high;
  }
  while (low<=high) {
    int mid = low+(high-low)/2;
    if(v[mid]==k)
    return mid;
    else if(v[mid]>k)
    high = mid-1;
    else
    low = mid+1;
  }
}
int main(){
  int n;cin>>n; //practically it is impossible to take infinite array
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  int k;cin>>k;
  cout<<find_k(v,k)<<endl;
return 0;
}

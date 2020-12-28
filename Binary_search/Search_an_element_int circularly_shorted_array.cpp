// Apporch is to find min_element in the array an on the basis of that we can decide
//In which side of min result may be present, then call binary_search for that segment
#include<iostream>
#include<vector>
using namespace std;
int min_index(vector<int>&v){
  int n = v.size();
  int low=0;
  int high = n-1;
  while (low<=high) {
    int mid = low+(high-low)/2;
    if(v[low]<=v[high])
    return low;
    int next = (mid+1)%n;
    int prev = (mid+n-1)%n;
    if(v[mid]<=v[prev] && v[mid]<=v[next])
    return mid;
    else if(v[mid]<=v[high])
    high = mid-1;
    else if(v[mid]>=v[low])
    low = mid+1;

  }
  return -1;
  }
  int binary_search(vector<int>&v,int key,int low,int high){
    while (low<=high) {
      int mid = low+(high-low)/2;
      if(v[mid]==key)
      return mid;
      else if(v[mid]>=key)
      high = mid-1;
      else if(v[mid]<=key)
      low = mid+1;
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
    int index = min_index(v);
    //cout<<index<<endl;
    int key;cin>>key;
  /*  if(key>[0])
    cout<<binary_search(v,key,0,index);
    else if(key<=v[n-1])
    cout<<binary_search(v,key,index,n-1);*/
    int x = binary_search(v,key,0,index);
    int y = binary_search(v,key,index,n-1);
    if(x!=-1)
    cout<<x<<endl;
    else if(y!=-1)
    cout<<y<<endl;
    else
    cout<<-1<<endl;
  }
return 0;
}

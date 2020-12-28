#include<iostream>
#include<vector>
using namespace std;
int key_index(vector<int>&v,int key){
  int l=0;
  int r = v.size()-1;
  int n = v.size();
  while (l<=r) {
    int m = l+(r-l)/2;
    if(v[m]==key)
    return m;
    else if(m-1>=l && v[m-1]==key)
    return m-1;
    else if(m+1<=r && v[m+1]==key)
    return m+1;
    else if(v[m]>key && m-2>=0)
    r = m-2;
    else if(v[m]<key && m+2<n)
    l = m+2;
    else
    return -1;
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
    int key;cin>>key;
    cout<<key_index(v,key);
  }
return 0;
}

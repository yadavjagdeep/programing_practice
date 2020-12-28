#include<iostream>
#include<vector>
using namespace std;
std::vector<int> v;
int find_min(int i,int j){
  if(i==j)
  return v[i];
   int mid = (i+j)/2;
   return min(find_min(i,mid),find_min(mid+1,j));
}
int main(){
  int n;cin>>n;
  v.clear();
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  cout<<find_min(0,v.size()-1)<<endl;
return 0;
}

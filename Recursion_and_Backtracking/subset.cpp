#include<iostream>
#include<vector>
using namespace std;
void ss(int i,vector<int>&a,vector<int>&v){
  if(i>=a.size()){
    for(auto x:v)
    cout<<x<<" ";
    cout<<"\n";
      return;
  }

  v.push_back(a[i]);
  ss(i+1,a,v);
  v.pop_back();
  ss(i+1,a,v);
}
int main()
{
  int n;cin>>n;
  vector<int>a;
    std::vector<int> v;
    for(int i=0;i<n;i++){
    int val;cin>>val;
      a.push_back(val);
  }
ss(0,a,v);
return 0;
}

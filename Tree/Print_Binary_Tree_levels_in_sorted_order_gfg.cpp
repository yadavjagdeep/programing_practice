#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int e=1;
    int s=0;
    int x = floor(log2(n));
    x+=1;
    for(int i=0;i<x;i++){
    if(e<n){
      sort(v.begin()+s,v.begin()+e);
      for(auto ptr = v.begin()+s;ptr<v.begin()+e;ptr++)
      cout<<*ptr<<" ";
    }else{
      sort(v.begin()+s,v.end());
      for(auto ptr = v.begin()+s;ptr<v.end();ptr++)
      cout<<*ptr<<" ";
    }

    s=e;
  e = (2*e)+s;
    cout<<endl;
    }
  }
}

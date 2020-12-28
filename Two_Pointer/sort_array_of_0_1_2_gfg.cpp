#include<iostream>
#include<vector>
using namespace std;
int main(){
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    std::vector<int> v;
    v.clear();
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int l=0,h=n-1,m=0;
    while (m<=h) {
      if(v[m]==0){
        swap(v[l],v[m]);
        l++;
        m++;
      }else if(v[m]==1)
      m++;
      else if(v[m]==2){
        swap(v[m],v[h]);
        h--;
      }
    }
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
  }
return 0;
}

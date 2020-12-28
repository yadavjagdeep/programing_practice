#include<iostream>
#include<vector>
using namespace std;
int mid(vector<int>&v,int l,int m,int r){
  int n = v.size();
  while (m<n-1 && r<n-1) {
    for(int i=m;i<n;i++){
      if(v[i]>=v[l]){
        m=i;
        l=i;
        r=i;
        break;
      }
    }
    for(int i=r;i<n;i++){
      if(v[i]<v[m]){
        r=i;
        m=i;
        break;
      }else{
        r++;
      }
    }
  }
if(l==n-1 || m==n-1)
return -1;

return v[m];
}
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
    int l=0,m=0,r=0;
    //cout<<l<<m<<r<<endl;
    if((n==3) && ((v[l]>v[m])||(v[r]<v[m])))
    cout<<-1<<endl;
    else
    cout<<mid(v,l,m,r)<<endl;
  }
return 0;
}

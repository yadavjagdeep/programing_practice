// max(at i longest decresing to left+longest decresing to right)
//consider example of an HUT ^
#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
std::vector<int> v;
int dpl[101];
int dpr[101];
int LDSR(int i){
  if(i==v.size()-1)
  return 1;
  if(dpr[i]!=-1)
  return dpr[i];
  int m = 1;
  for(int y=i+1;y<v.size();y++){
    if(v[y]<v[i])
    m  = max(m,1+LDSR(y));
  }
return dpr[i] = m;
}
int LDSL(int i){
  if(i==0)
  return 1;
  int m = 1;
  if(dpl[i]!=-1)
  return dpl[i];
  for(int y=i-1;y>=0;y--){
    if(v[y]<v[i])
    m  = max(m,1+LDSL(y));
  }
return dpl[i] = m;
}
int main(){
  int t;cin>>t;
  while (t--) {
          memset(dpl,-1,sizeof(dpl));
          memset(dpr,-1,sizeof(dpr));
    v.clear();
    int n;cin>>n;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int lans=0;
    int rans = 0;
    int ans=0;
    for(int i=0;i<n;i++){

      ans = max(ans,(LDSL(i)+LDSR(i))-1);
    }
    cout<<ans<<endl;
  }

return 0;
}

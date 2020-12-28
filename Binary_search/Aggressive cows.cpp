#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<int>&v,int c,int m){
  int count=1;
  int temp = v[0];
  for(int i=1;i<v.size();i++){
    if((v[i]-temp)>=m){
      count++;
      temp = v[i];
    }
  }
  if(count<c)
  return false;
return true;
}
int min_distance(vector<int>&v,int c){
  int low = *min_element(v.begin(),v.end());
  int high = *max_element(v.begin(),v.end());
  int ans;
  while (low<=high) {
    int mid = ((low+high)/2);
    if(issafe(v,c,mid)){
      low = mid+1;
      ans=mid;
    }
    else
    high = mid-1;
  }
return ans;
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n,c;
    cin>>n>>c;
    std::vector<int> v;
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    sort(v.begin(),v.end());
    cout<<min_distance(v,c)<<endl;
  }
return 0;
}

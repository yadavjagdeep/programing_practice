#include<iostream>
#include<vector>
using namespace std;
int find(vector<vector<int>>&v,int k,int n,int m){
  int i=0,j=m-1;
  while (i<n && j>=0) {
    if(v[i][j]==k)
    return 1;
    else if(v[i][j]>k)
    j--;
    else
    i++;
  }
return 0;
}
int main(){
  int t;cin>>t;
  while (t--) {
    int n,m;
    cin>>n>>m;
    std::vector<vector<int>> v;
    v.clear();
    for(int i=0;i<n;i++){
      std::vector<int> row;
      for(int j=0;j<m;j++){
        int val;cin>>val;
        row.push_back(val);
      }
      v.push_back(row);
      row.clear();
    }
    int k;cin>>k;
    cout<<find(v,k,n,m)<<endl;
  }
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
void print(vector<vector<int>>&v){
//  int n=v.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<v[i][j]<<" ";
    }
    cout<<'\n';
  }
}
bool is_safe(vector<vector<int>>&v,int l,int r,int k){
  //top check
  for(int i=l-1;i>=0;i--){
    if(v[i][r]==k)
    return false;
  }
  //bottom check
  for(int i=l+1;i<n;i++){
    if(v[i][r]==k)
    return false;
  }
  //left check
  for(int i=r-1;i>=0;i--){
    if(v[l][i]==k)
    return false;
  }
  //right check
  for(int i=r+1;i<n;i++){
    if(v[l][i]==k)
    return false;
  }
int s = sqrt(n);
  l = l-l%s;
  r = r-r%s;
  for(int i=l;i<l+s;i++){
    for(int j=r;j<r+s;j++){
      if(v[i][j]==k)
      return false;
    }
  }
return true;
}
bool suduko(vector<vector<int>>&v,int i,int j){
    if(i==n-1 && j==n)
    return true;
    if(j==n){
      j=0;
      i++;
    }
    if(v[i][j]==0){
      for(int k=1;k<=n;k++){
        if(is_safe(v,i,j,k)){
          v[i][j]=k;
          if(suduko(v,i,j+1)==true)
          return true;
          v[i][j]=0;
        }
      }
      return false;
    }else if(suduko(v,i,j+1))
    return true;
}
int main(){
  cin>>n;
  vector<vector<int>>v;
  for(int i=0;i<n;i++){
    vector<int>row;
    for(int j=0;j<n;j++){
      int val;cin>>val;
      row.push_back(val);
    }
    v.push_back(row);
  }
  suduko(v,0,0);
  print(v);
return 0;

}

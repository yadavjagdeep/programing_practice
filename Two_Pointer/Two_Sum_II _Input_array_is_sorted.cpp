#include<iostream>
#include<vector>
using namespace std;
void find_index(vector<int>&v,int k){
  int ptrl=0;
  int ptrr=v.size()-1;
  while (true) {
    if((v[ptrl]+v[ptrr])==k)
    break;
    else if((v[ptrl]+v[ptrr])>k)
    ptrr--;
    else
    ptrl++;
  }
  cout<<ptrl+1<<" "<<ptrr+1<<endl;
}
int main(){
  int n;cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++){
    int val;cin>>val;
    v.push_back(val);
  }
  int k;cin>>k;
  find_index(v,k);
return 0;
}

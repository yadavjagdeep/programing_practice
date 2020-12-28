#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
std::vector<int> p;
std::vector<int> wt;
int weight;

int pmax(int i,int w){
  if(i==p.size())
  return 0;
if(w+wt[i]>weight)
return pmax(i+1,w);
  return max(p[i]+pmax(i+1,w+wt[i]),pmax(i+1,w)) ;



}
int main(){
  int n;cin>>n;

  for(int i=0;i<n;i++){
    int val;cin>>val;
    wt.push_back(val);
  }
  for(int i=0;i<n;i++){
    int val;cin>>val;
    p.push_back(val);
  }
  cin>>weight;
  cout<<pmax(0,0)<<endl;
return 0;
}

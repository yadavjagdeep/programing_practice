
#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
int n;
  std::vector<int> v;
int findbuy(int x){
  for(int i=x+1;i<n;i++){
    if(v[i]>v[i-1])
    return i-1;
  }
return -1;
}
int findsell(int buy){
  for(int i=buy+1;i<n;i++){
    if(v[i]<v[i-1])
    return i-1;
  }
return n-1;
}
int main(){
  int t;cin>>t;
  while (t--) {
    cin>>n;
  v.clear();
    for(int i=0;i<n;i++){
      int val;cin>>val;
      v.push_back(val);
    }
    int buy=-1;
    int sell=0;
    for(int i=1;i<n;i++){
      if(v[i]>v[i-1]){
        buy = i-1;
        break;
      }
    }
    if(buy==-1)
    cout<<"No Profit"<<endl;
    else{
      while (buy<n) {
        buy = findbuy(sell);
        if(buy==-1)
        break;
        sell = findsell(buy);
        cout<<'('<<buy<<" "<<sell<<')'<<" ";

        if(sell==n-1)
        break;

      }
    }
    cout<<endl;
  }
return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
int dp[100001];
int moves(string str,string s,int i){
//cout<<s<<endl;
  if(str == s)
  return 0;
  if(dp[i]!=-1)
  return dp[i];
  if((i<=(str.size()/2)) && (str.substr(i,i)==s)){
  // cout<<"ok"<<endl;
    return dp[i] = min(1+moves(str,s+str.substr(i,i),i+i),1+moves(str,s+str[i],i+1));
  }else{
    return dp[i]=1+moves(str,s+str[i],i+1);
  }
}
int main(){
  int t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
     string str;cin>>str;
    string s="";
    s+=str[0];
     cout<<1+moves(str,s,1)<<endl;
  }
return 0;
}

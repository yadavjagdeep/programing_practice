#include<bits/stdc++.h>
using namespace std;
bool is_valid(string str){
  stack<char>s;
  for(int i=0;i<str.size();i++){
    if(str[i]=='(' || str[i]=='{' || str[i]=='['){
      s.push(str[i]);
    }else if(str[i]==')'){
      if(s.empty())
      return false;
      if(s.top()!='(')
      return false;
      s.pop();
    }else if(str[i]=='}' ){
      if(s.empty())
      return false;
      if(s.top()!='{')
      return false;
      s.pop();
    }else if(str[i]==']'){
      if(s.empty())
      return false;
      if(s.top()!='[')
      return false;
      s.pop();
    }
  }
  if(!s.empty())
  return false;
return true;
}
int main(){
  string str;cin>>str;
  if(is_valid(str))
  cout<<"VALID"<<'\n';
  else
  cout<<"INVALID"<<'\n';
return 0;
}

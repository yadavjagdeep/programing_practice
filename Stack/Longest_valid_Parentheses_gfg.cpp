#include<bits/stdc++.h>
using namespace std;
void left_check(string &str){
  int cnt=0;
  for(int i=0;i<str.size();i++){
    if(str[i]=='(')
    cnt++;
    else if(str[i]==')')
    cnt--;

    if(cnt<0){
      str[i]='#';
      cnt=0;
    }
  }
}

void right_check(string &str){
  int cnt=0;
  for(int i=str.size()-1;i>=0;i--){
    if(str[i]==')')
    cnt++;
    else if(str[i]=='(')
    cnt--;

    if(cnt<0){
      str[i]='#';
      cnt=0;
    }
  }
}
int lvp(string &str){
  stack<char>s;
  for(auto x:str)
  s.push(x);

  int max_length=0,cnt=0;
  while(!s.empty()){
    if(s.top()!='#')
    cnt++;
    else
      cnt=0;
    max_length = max(max_length,cnt);
    s.pop();
  }
return max_length;
}
int main(){
  string str;cin>>str;
  left_check(str);
  right_check(str);
  cout<<lvp(str)<<'\n';
return 0;
}

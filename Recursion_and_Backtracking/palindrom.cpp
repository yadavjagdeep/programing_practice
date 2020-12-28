#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdbool>
using namespace std;
bool pali(string str)
{
  if(str.length()<2)
  return true;
   if(!(str[0]==str[str.length()-1]))
  return false;
  return pali(str.substr(1,str.length()-2));
}
int main()
{
  string str = "abcba";
  if(pali(str))
  cout<<"Palindrom"<<endl;
  else
  cout<<"Not Palindrom"<<endl;
//  cout<<str.length();
return 0;
}

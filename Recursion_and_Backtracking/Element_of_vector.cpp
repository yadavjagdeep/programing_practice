#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
void print(int a[],int i,int n)
{
  if(i>n)
  return;
  cout<<a[0]<<" ";
  return print(a+1,i+1,n);

}
int main(){
  int a[20];
  int n;cin>>n;
  for(int i=0;i<n;i++)
  cin>>a[i];
  print(a,0,n-1);
  return 0;
}

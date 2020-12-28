#include<iostream>
#include<vector>
#define mod 1000000007
#define ll unsigned long long int
using namespace std;
int main(){
  ll a[1001][1001]={0};
  ll x=1;
  for(ll i=0;i<1001;i++){
    a[i][0]=x;
    x++;
    for(ll j=1;j<i+1;j++){
      a[i][j] = ((a[i-1][j-1])%mod+(a[i-1][j])%mod)%mod;
    }
  }
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    int r;cin>>r;
    cout<<a[n-1][r-1]<<endl;
  }

return 0;
}

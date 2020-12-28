#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll dp[1001][1001];
ll mat[1005][1005];
  ll n,m,k;
    std::vector<pair<ll,ll>> v;
  bool check(ll x,ll y){
    //cout<<v.size()<<endl;
    for(ll i=0;i<v.size();i++){
      pair<ll,ll>p1 = v[i];
     //cout<<p1.first<<" "<<p1.second<<endl;
      if(p1.first==x && p1.second==y)
      return true;
    }
  return false;
  }
ll ways(ll i,ll j){
  if(mat[i][j]==1)
  return 0;
  if(i==n && j==m)
  return 1;
   if(i>n || j>m)
  return 0;
  if(dp[i][j]!=-1)
  return dp[i][j];
  return dp[i][j]=(ways(i,j+1)%mod+ways(i+1,j)%mod)%mod;
}
int main()
{
  ll t;cin>>t;
  while (t--) {
    memset(dp,-1,sizeof(dp));
    memset(mat,0,sizeof(mat));
    cin>>n>>m>>k;

    for(ll i=0;i<k;i++){
      ll x,y;
      cin>>x>>y;
      //pair<ll,ll>p;
    //  p.first = x;
      //p.second = y;
      //v.push_back(p);
      mat[x][y]=1;
    }
    cout<<ways(1,1)<<endl;
    v.clear();
  }
return 0;
}

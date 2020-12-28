#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1001];
	vector<int>v;
		int n;
int lis(int x){
	if(x==n-1)
	return 1;
	if(dp[x]!=-1)
	return dp[x];
	int ans = 1;
	for(int i=x+1;i<n;i++){
		if(v[i]>v[x])
		ans = max(ans,1+lis(i));
	}
return dp[x] = ans;
}
int main() {
	int t;cin>>t;
	while(t--){
	    memset(dp,-1,sizeof(dp));
	cin>>n;
	v.clear();
		for(int i=0;i<n;i++){
			int val;cin>>val;
			v.push_back(val);
		}
		int ans = 1;
		for(int i=0;i<n;i++){
			ans = max(ans,lis(i));
			//	cout<<ans<<endl;
		}
		cout<<ans<<endl;

	}
	return 0;
}

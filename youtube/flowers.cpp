#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int M = 1e9+7;
vector<int> dp(N+5,-1);
vector<int> prefix(N+5,0);
int func(int ind,int k){

	if(ind==0) return 1;
	if(dp[ind]!=-1) return dp[ind];
	int nottake = func(ind-1,k);
	int take=0;
	if(ind-k>=0) take=func(ind-k,k);
	return dp[ind]=take+nottake;
  
}


int main(int argc, char const *argv[])
{	
	int t,k;
	cin>>t>>k;
	// int ans=func(len,k);

	// for(int i=1;i<k;i++) dp[i]=1;
	// dp[k]=2;
	// for(int i=k+1;i<=N;i++) dp[i]=(dp[i-1]+dp[i-k])%M;

	// cout<<func(len,k)<<endl;
	// for(int i=1;i<=N;i++) cout<<dp[i]<<" ";

	dp[0]=1;
	for(int ind=1;ind<=N;ind++){
		int nottake = dp[ind-1];
		int take=0;
		if(ind-k>=0) take=dp[ind-k];
		dp[ind]=(take+nottake)%M;

	}



	prefix[0]=0;	
	prefix[1]=dp[1];
	for(int i=2;i<=N;i++) prefix[i]=(prefix[i-1]+dp[i])%M;

	// cout<<endl;
	// for(int i=1;i<=len;i++) cout<<prefix[i]<<" ";

	while(t--){
		int a,b;
		cin>>a>>b;
		int ans=(prefix[b]-prefix[a-1])%M;
		if(ans<0) ans+=M;
		cout<<ans<<endl;
	}


	

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,h,l,r;
vector<int> arr(2005,0);
vector<vector<int>> dp(2005,vector<int>(2005,0));
int func(int ind,int t){

	if(ind==n) return 0;
	if(dp[ind][t]!=-1) return dp[ind][t];
	//option one
	int t1=(arr[ind]+t)%h;
	int cnt1=0;
	if(t1>=l && t1<=r) cnt1=1;
	int op1 = func(ind+1,t1)+cnt1;

	//option two
	int t2=(t + arr[ind]-1)%h;
	int cnt2=0;
	if(t2>=l && t2<=r) cnt2=1;
	int op2= func(ind+1,t2)+cnt2;

	return dp[ind][t]=max(op1,op2); 
}
int main(int argc, char const *argv[])
{
	cin>>n>>h>>l>>r;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// int ans=func(0,0);
	// cout<<ans<<endl;
	for(int ind=n-1;ind>=0;ind--){
		for(int t=0;t<h;t++){
			//option one
			int t1=(arr[ind]+t)%h;
			int cnt1=0;
			if(t1>=l && t1<=r) cnt1=1;
			int op1 = dp[ind+1][t1]+cnt1;

			//option two
			int t2=(t + arr[ind]-1)%h;
			int cnt2=0;
			if(t2>=l && t2<=r) cnt2=1;
			int op2= dp[ind+1][t2]+cnt2;

			dp[ind][t]=max(op1,op2);
		}
	}

	cout<<dp[0][0]<<endl;


	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{	
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		//n is zeros nd m is ones
		cin>>n>>m;
		long long groups=m+1;
		long long zero=(n-m)/groups;
		long long left=(n-m)%groups;
		long long g1_size= zero + 1;
		long long g1_number= left;
		long long g2_size= zero;
		long long g2_number=groups-left;

		long long ans = (n*(n+1)/2)-(g1_size*(g1_size+1)/2*g1_number + g2_size*(g2_size+1)/2*g2_number);
		cout<<ans<<endl;

	}
	
	return 0;
}

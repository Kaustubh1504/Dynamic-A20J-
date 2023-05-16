#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k;
	cin>>n>>k;

	long long arr[n];
	for(long long i=0;i<n;i++) cin>>arr[i];

	long long total=0;
    long long ctr=0;
    for(long long i=n;i>=0;i--){
    	ctr++;
    	total+=i;
		if(ctr>=k) break; 
    }

    vector<long long> ind;

    long long other = n - k;
    for(long long i=0;i<n;i++){
    	if(arr[i]>other) ind.push_back(i);
    }

    long long ways=1;
    for(long long i=1;i<ind.size();i++){
    	long long diff = ind[i]-ind[i-1];
    	// ways*=()%998244353;
    	ways=(ways*diff)%998244353;
    }

    cout<<total<<" "<<ways;
	
	return 0;
}
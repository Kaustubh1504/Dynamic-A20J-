#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1];
		for(int i=0;i<n;i++) cin>>arr[i];
		map<int,vector<int>> freq;

		for(int i=0;i<n;i++){
			freq[arr[i]].push_back(i);
		}

		// for(auto itr: freq){
		// 	for(auto i: itr.second){
		// 		cout<<i<<" ";
		// 	}
		// 	cout<<endl;
		// }
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		int ans=INT_MAX;
		for(auto itr:freq){

			if(itr.second.size()==1){
				if(itr.second[0]==0 || itr.second[0]==n-1){
					ans=min(ans,1);
				}else{
					ans=min(ans,2);
				}
			}
			else{
				int ok=0;
				for(int i=0;i<itr.second.size();i++){
					
					if(i==0){
						//first is zero 
						if(itr.second[i]>=1) ok++;
						continue;
					}
					if(i==itr.second.size()-1){
						//ind is last
						if(itr.second[i]<(n-1)) ok++;
					}
					if(itr.second[i]-itr.second[i-1]>1){
						ok++;
					}
				}

				ans=min(ans,ok);
			}
			
		}

		cout<<ans<<endl;


	}
	return 0;
}

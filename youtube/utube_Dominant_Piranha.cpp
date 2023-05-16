#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int arr[n];
	    set<int> st;
		int maxi=0;
		for(int i=0;i<n;i++){ 
			cin>>arr[i];
			st.insert(arr[i]);
			maxi=max(maxi,arr[i]);
		}

		if(st.size()==1){
			cout<<"-1"<<endl;
			continue;
		}

		for(int i=0;i<n;i++){
			if(arr[i]==maxi){
				if(i-1>=0 && arr[i-1]<maxi){
					cout<<i+1<<endl;
					break;
				}
				else if(i+1<n && arr[i+1]<maxi){
					cout<<i+1<<endl;
					break;

				}
				
			}
		}
	}
	return 0;
}
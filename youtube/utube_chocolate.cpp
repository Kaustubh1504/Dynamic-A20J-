#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
    
    int noofnuts=0;
    for(int i=0;i<n;i++) {
    	cin>>arr[i];
    	if(arr[i]==1) noofnuts++;
    }

    if(noofnuts==0){
    	cout<<"0";
    	return 0;
    }
    // cout<<noofnuts<<endl;
    // for(int i=0;i<n;i++) cout<<arr[i];

    stack<int> st;
    long long ans=1;
    for(int i=0;i<n;i++){
    	if(arr[i]==1){
    		if(!st.empty()){
    			int m = i-st.top() ;
    			ans*=m;
    		}
    		st.push(i);
    	}
    }

    cout<<ans;
	return 0;
}
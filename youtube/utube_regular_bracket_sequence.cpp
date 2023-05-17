#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int n = s.size();
	stack<int> st;
	vector<int> dp(n,0);

	for(int i=0;i<n;i++){
		char c= s[i];
		if(c=='('){
			st.push(i);
		}else{
			if(st.empty()) continue;
			int j=st.top();
			st.pop();

			dp[i]=i-j+1+(j>=1?dp[j-1]:0);

		}
	}

	// for(int i=0;i<n;i++) cout<<dp[i]<<" ";
	// cout<<endl;
	
   int len=0,cnt=0;	
   for(int i=0;i<n;i++){
   		if(dp[i]>len){
   			len=dp[i];
   			cnt=1;
   		}else if(dp[i]==len) cnt++;
   }
   if(len==0) cout<<"0 1";
   else cout<<len<<" "<<cnt;
	return 0;
}
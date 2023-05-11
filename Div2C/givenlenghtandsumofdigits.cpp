#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	
	int m,s;
	cin>>m>>s;
	string maxi="";
	string mini="";

	if(s==0){
		if(m==1){
			cout<<"0 0";
			return 0;
		}
		else
			cout<<"-1 -1";

		return 0;

	}

	
	for(int i=0;i<m;i++){
		int k=min(9,s);
		maxi.push_back('0'+k);
		s-=k;
	}

	if(s>0){
		cout<<"-1 -1";
		return 0;
	}

	for(int i=m-1;i>=0;i--) mini.push_back(maxi[i]);

	int j=0;
	while(mini[j]=='0') j++;

	mini[0]++;
	mini[j]--;

	cout<<mini<<" "<<maxi;

	return 0;
}

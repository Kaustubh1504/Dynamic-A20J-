/*
  out state contains (r s p) whick are the no of 
  rock papers and scisoors remaining in the end 

  case1: a rock and scisoor meet => (r,s-1,p);
  case2: a scisoor and a paper meet=>(r,s,p-1);
  case3: a paper and a rock meet=> (r-1,s,p);

  let dp1(r,s,p) be the probablity that a rock 
  remains the surviour int the end

  and similarly dp2(r,s,p) is the probablity thaa s scisor survives
  and dp3(r,s,p) would be the probablity that a paper survies


  base cases:
  part1:
  dp1(0,s,p) = 0 because no rocks are left
  dp2(r,0,p) =0 
  and dp3(r,s,0)=0

  part2:
  dp1(r,0,0)=1 bec only rocks are left
  dp2(0,s,0)=1
  dp3(0,0,p)=1


 analysing our transition
 the probablity of event A happing is the no
 of ways A can happen/totol#

 total#of interactions = r*s + s*p+p*r
 (because a rock and a scisoor can meet in
 r*s # of ways and similarly a scissor and a paper can meet in 
 s*p ways and a rock and a paper can meet in p*r ways)


 denominator(total)=r*s + s*p + p*r;

 dp1 or dp2 or dp3:(r*s)/(r*s + s*p + p*r)=> probablity that a rock meets a scissor and this goes to state (r,s-1,p)

     (s*p)/(r*s + s*p + p*r)=> probablity tha a scisoor meets a paper and this goes to state (r,s,p-1)

     (r*p)/(r*s+ s*p + p*r)=> probablity that a rock meets a paper and this goes to state (r-1,s,p)


observe : only base cases differ for dp1,dp2 and dp3
(transitions remain the same)
*/

#include<bits/stdc++.h>
using namespace std;

const int N =101;
vector<vector<vector<long double>>> dp1(N,vector<vector<long double>>(N,vector<long double>(N,-1)));
vector<vector<vector<long double>>> dp2(N,vector<vector<long double>>(N,vector<long double>(N,-1)));
vector<vector<vector<long double>>> dp3(N,vector<vector<long double>>(N,vector<long double>(N,-1)));

long double solve1(long double r,long double s,long double p){

	if(r==0) return dp1[r][s][p]=0;
	if(r>0 && s==0 && p==0) return dp1[r][s][p]=1;

	if(dp1[r][s][p]!=-1) return dp1[r][s][p];

	long double all=r*s+s*p+r*p;
	long double ans=0;

	if(s>0 && r>0) ans+=((r*s)/all)*solve1(r,s-1,p);
	if(p>0 && s>0) ans+=((s*p/all))*solve1(r,s,p-1);
	if(r>0 && p>0) ans+=((r*p)/all)*solve1(r-1,s,p);

	return dp1[r][s][p]=ans;
}

long double solve2(long double r,long double s,long double p){

	if(s==0) return dp2[r][s][p]=0;
	if(r==0 && s>0 && p==0) return dp2[r][s][p]=1;

	if(dp2[r][s][p]!=-1) return dp2[r][s][p];

	long double all=r*s+s*p+r*p;
	long double ans=0;

	if(s>0 && r>0) ans+=((r*s)/all)*solve2(r,s-1,p);
	if(p>0 && s>0) ans+=((s*p/all))*solve2(r,s,p-1);
	if(r>0 && p>0) ans+=((r*p)/all)*solve2(r-1,s,p);

	return dp2[r][s][p]=ans;
}

long double solve3(long double r,long double s,long double p){

	if(p==0) return dp3[r][s][p]=0;
	if(r==0 && s==0 && p>0) return dp3[r][s][p]=1;

	if(dp3[r][s][p]!=-1) return dp3[r][s][p];

	long double all=r*s+s*p+r*p;
	long double ans=0;

	if(s>0 && r>0) ans+=((r*s)/all)*solve3(r,s-1,p);
	if(p>0 && s>0) ans+=((s*p/all))*solve3(r,s,p-1);
	if(r>0 && p>0) ans+=((r*p)/all)*solve3(r-1,s,p);

	return dp3[r][s][p]=ans;
}
int main(int argc, char const *argv[])
{
	long double r,s,p;
	cin>>r>>s>>p;
	cout.precision(9);
	cout<<fixed<<solve1(r,s,p)<<" "<<solve2(r,s,p)<<" "<<solve3(r,s,p);

	return 0;
}
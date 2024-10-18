#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repr(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18+1

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}

int n,m;
string s,t;
int dp[3001][3001];

void solve()
{ 
	cin>>s>>t;
	n= s.size(); m = t.size();

	rep(i,1,n)
	{
		rep(j,1,m)
		{
			if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
		
	}
	
	int i=n,j=m;

	string ans ="";

	while(i>0 && j>0)
	{
		if(dp[i][j]==dp[i][j-1]){ j--;}
		else if(dp[i][j]==dp[i-1][j])i--;
		else{ans=s[i-1]+ans;i--;j--;} 

		
	}
  // reverse(ans.begin(),ans.end());
	cout<<ans<<endl;

return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}

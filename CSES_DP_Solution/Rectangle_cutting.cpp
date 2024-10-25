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

int const N=501;
int a,b;
int dp[N][N];


void solve()
{
cin>>a>>b;
rep(i,1,a)
{
	rep(j,1,b)
	{
		if(i==j)dp[i][j]=0;
		else
		{
		dp[i][j]= 1e18;

		for(int k=1; 2*k<=i;k++)
		{
			dp[i][j] = min(dp[k][j]+dp[i-k][j]+1,dp[i][j]);
		}

		for(int k=1; 2*k<=j;k++)
		{
			dp[i][j] = min(dp[i][k]+dp[i][j-k]+1,dp[i][j]);
		}
	}
	}
}

cout<<dp[a][b]<<endl;


}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}

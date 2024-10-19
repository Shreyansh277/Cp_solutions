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

int n;
vector<vector<int>> g;
int dp[100001][2];



int f(int node ,int pr,int col)
{
	if(dp[node][col]!=-1) return dp[node][col];
	int ans=1;

	for(auto z: g[node])
	{
		if(z!=pr)
		{
			if(col==0) ans = (ans*f(z,node,1))%mod;
			else ans = (ans*(f(z,node,0)+f(z,node,1)))%mod;
		}
	}

	return dp[node][col]=ans;
}



void solve()
{
	cin>>n; 
g.resize(n+1);

rep(i,1,n-1)
{
	int x,y; cin>>x>>y;
	g[x].pb(y);
	g[y].pb(x);
}
memset(dp,-1,sizeof(dp));
int ans = (f(1,-1,0)+f(1,-1,1))%mod;
// int ans=0;
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

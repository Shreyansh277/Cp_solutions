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
vector<vector<int>> g;
int dp[100001];

// int ans=0;

int  rec(int node)
{
	
if(g[node].empty())return 0;
if(dp[node]!=-1)return dp[node];
int ans =0;
for(auto z: g[node])
{
	ans = max(ans,rec(z)+1);
}
return dp[node]= ans;
}


void solve()
{ 
	cin>>n>>m;
	g.resize(n+1);
	rep(i,1,m)
	{
		int x,y; cin>>x>>y; 
		g[x].pb(y);
	}

	memset(dp,-1,sizeof(dp));

  int ans =0;
	rep(i,1,n)ans = max(ans,rec(i));

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

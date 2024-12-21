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
// #define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18+1
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}


// graph algorithms 
// counting rooms 

int n,m;
vector<vector<int>>g;
vector<int> color;

void dfs(int i)
{
	color[i]=1;
	for(auto z: g[i])
	{
		if(color[z]==0)dfs(z);
	}

	color[i]=2;
	return;
}

void solve()
{
cin>>n>>m;

g.resize(n+1);
color.assign(n+1,0);
rep(i,1,m)
{
	int a,b; cin>>a>>b; 
	g[a].pb(b);
	g[b].pb(a);
} 

vector<int> ans;

rep(i,1,n)
{
	if(color[i]==0){dfs(i); ans.pb(i);}
}


cout<<ans.size()-1<<endl;
rep(i,1,ans.size()-1)
{
	cout<<ans[0]<<" "<<ans[i]<<endl;
}

return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
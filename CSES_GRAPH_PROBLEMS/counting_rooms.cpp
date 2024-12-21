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

char mat[1001][1001];
int color[1001][1001];
int n,m,rooms=0;

int dx[]= {1 ,-1, 0 ,0};
int dy[]= {0,0,1,-1};

vector<pair<int,int>> neighbours(int i,int j)
{
	vector<pair<int,int>> v;

	rep(l,0,3)
	{
		int tx= i+dx[l];
		int ty= j+dy[l];

		if(tx<=n && tx>=1 && ty<=m && ty>=1 && mat[tx][ty]=='.')v.pb({tx,ty});
	}
  return v;
}

void dfs(int i,int j)
{
	color[i][j]=1;
	auto v = neighbours(i,j);

	for(auto z: v)
	{
		if(color[z.f][z.s]==0)dfs(z.f,z.s);
	}

	color[i][j]=2;
	return;
}

void solve()
{
cin>>n>>m;

rep(i,1,n)
{
	rep(j,1,m)cin>>mat[i][j];
} 


rep(i,1,n)
{
	rep(j,1,m)
	{
		if(mat[i][j]=='.' && color[i][j]==0)
		{
			dfs(i,j);
			rooms++;
		}
	}
}


cout<<rooms<<endl;

return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
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
char mat[1001][1001];
int dp[1001][1001];


int f(int i,int j)
{

	if(mat[i][j]=='*')return 0;
  
  if(i==1 && j==1)return (mat[i][j]=='.')?1:0;
	if(dp[i][j]!=-1)return dp[i][j];

	int ans =0;

	if(i>1)ans = f(i-1,j);
	if(j>1)ans+=f(i,j-1);

	return dp[i][j]=ans%mod;


}

void solve()
{ 
	cin>>n;
	rep(i,1,n)
	{
		rep(j,1,n)cin>>mat[i][j];
	}
	memset(dp,-1,sizeof(dp));
	cout<<f(n,n)<<endl;


return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}

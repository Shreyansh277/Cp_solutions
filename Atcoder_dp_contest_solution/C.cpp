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
int a[100005][4];
int dp[100005][4];

int f(int level,int acc)
{
	if(level==n) return 0;

	if(dp[level][acc]!=-1)return dp[level][acc];

	int ans =-1*inf;

	rep(i,1,3)
	{
		if(i!=acc)
		{
			ans = max(ans,f(level+1,i)+a[level+1][i]);
		}
		
	}
	// cout<<ans<<endl;

	return dp[level][acc]= ans;
}




void solve()
{
cin>>n;
memset(dp,-1,sizeof(dp));
rep(i,1,n)cin>>a[i][1]>>a[i][2]>>a[i][3];

// cout<<n<<endl;
int ans = f(0,0);

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
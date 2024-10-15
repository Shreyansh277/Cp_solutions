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


int n,w;
int a[100][2];
int dp[100][100001];

int f(int level ,int wi)
{
	if(level==n)return 0;
	if(dp[level][wi]!=-1)return dp[level][wi];

	int ans = f(level+1,wi);
	if(wi>=a[level][0])ans = max(f(level+1,wi-a[level][0])+a[level][1],ans);

	return dp[level][wi]= ans;


}

void solve()
{
cin>>n>>w; memset(dp,-1,sizeof(dp));
rep(i,0,n-1)cin>>a[i][0]>>a[i][1];

int ans = f(0,w);

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
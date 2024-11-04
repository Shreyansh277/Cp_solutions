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

int dp[500][130000];
int n;

int f(int level,int sum)
{
	if(sum==0)return 1;
	if(level==n)return 0;

	if(dp[level][sum]!=-1)return dp[level][sum];

	int ans = f(level+1,sum);
	if(sum-level-1>=0)(ans +=f(level+1,sum-level-1))%=mod;

	return dp[level][sum]=ans;
}

void solve()
{
 
  cin>>n;

 int s = n*(n+1)/2;

 if(s%2)cout<<0<<endl;
 else
 {
 	s/=2;
 	memset(dp,-1,sizeof(dp));
int ans = f(0,s);
 (ans *= _BinPow(2,mod-2,mod))%=mod;
 	cout<<ans<<endl;
 }


 
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}

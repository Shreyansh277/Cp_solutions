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


int n,k;
int dp[1000001];






void solve()
{
int a,ans=1; cin>>a;
int n=a;

if(dp[a]!=-1)
{
	cout<<dp[a]<<endl;
	return;
}

for(int i=2;i*i<=a;i++)
{
	int s=0;
	while(a%i==0)
	{
    s++; a/=i;
	}

	ans*= (s+1);
}

if(a>1)ans*=2;

dp[n]=ans;

cout<<ans<<endl; 
return;




}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	cin>>_T;
	memset(dp,-1,sizeof(dp));
  while(_T--)solve();
  return 0;  
}

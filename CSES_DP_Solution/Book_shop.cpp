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

int const N=1e5+10;
int n,x;
int dp[N],h[1001],s[1001];


void solve()
{
cin>>n>>x;
rep(i,1,n)cin>>h[i];
rep(i,1,n)cin>>s[i];

rep(i,1,n)
{
	repr(j,x,0)
	{
		if(j-h[i]>=0)dp[j]= max(dp[j],dp[j-h[i]]+s[i]);
	}
}


cout<<dp[x]<<endl;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}

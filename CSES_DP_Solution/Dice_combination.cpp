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
int dp[1000001];

void solve()
{
cin>>n;
cout<<dp[n]<<endl;


return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
	dp[0]=1;
	for(int i=1;i<1000001;i++)
	{
		for(int j=1;i-j>=0 && j<=6;j++)
		{
			dp[i]+=dp[i-j];
		}
		dp[i]%=mod;
	}
  while(_T--)solve();
  return 0;  
}
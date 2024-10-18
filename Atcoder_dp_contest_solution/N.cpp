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
int dp[401][401];
int a[401];
int p[401];

int f(int l,int r)
{
	if(r==l)return 0;
	if(dp[l][r]!=-1)return dp[l][r];

	int ans =inf;

	rep(i,l,r-1)
	{
		ans =  min(ans,p[r]-p[l-1]+f(l,i)+f(i+1,r));
	}

return dp[l][r]= ans;
}



void solve()
{ 
 cin>>n;
 rep(i,1,n){cin>>a[i];p[i]= p[i-1]+a[i];}
 memset(dp,-1,sizeof(dp));
 

int ans = f(1,n);

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
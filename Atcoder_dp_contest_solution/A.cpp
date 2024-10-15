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

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}


int n;
vector<int>v;
vector<int> dp;

int f(int level)
{
	if(level>=n) return 0;

	if(dp[level]!=-1)return dp[level];

	int ans = f(level+1) + abs(v[level+1]-v[level]);
	if(level+2<=n)ans = min(ans,f(level+2)+ abs(v[level+2]-v[level]));

	return dp[level]= ans;
}




void solve()
{
cin>>n; v.resize(n+1); dp.assign(n+1,-1);

rep(i,1,n)cin>>v[i];

int ans = f(1);

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
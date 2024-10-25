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
int a[3001];
int dp[3001][3001];


int f(int l,int r,int t)
{
	if(l==r)
	{
		if(t==2)return a[l];
		else return 0;
	} 
  if(dp[l][r]!=-1)return dp[l][r];

  int ans=0;
  if(t==1)
  {
  	ans = min(f(l+1,r,2),f(l,r-1,2));
  }
  else 
  {
  	ans = max(a[l]+f(l+1,r,1),a[r]+f(l,r-1,1));
  }

  return dp[l][r]=ans;
}



void solve()
{ 
	cin>>n;
	int s =0;
	memset(dp,-1,sizeof(dp));
	rep(i,1,n){cin>>a[i];s+=a[i];}
	// cout<<s<<endl;
	int ans= f(1,n,1);
	ans = s-2*ans;
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

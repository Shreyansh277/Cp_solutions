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

int dp[101][100001];
int v[100];
int w[100];
int n,W;


int f(int level,int value)
{
	 if(value==0)return 0;
   if(level>=n)return 1e17;
   if(dp[level][value]!=-1)return dp[level][value];

   int ans = f(level+1,value);
   if(value-v[level]>=0)ans = min(ans,w[level]+f(level+1,value-v[level]));

   return dp[level][value]= ans;
}


void solve()
{ 
	cin>>n>>W;
	rep(i,0,n-1)cin>>w[i]>>v[i];
	memset(dp,-1,sizeof(dp));

	int ans=0;

	repr(i,100000,1)
	{
		if(f(0,i)<=W){ans=i;break;}
		
	}

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

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
int a[100];
int dp[100][100005];

// dp[x][y] at x pos and distributed y candies 
// dp[x][0]==1  dp[first][0]==dp[first][1] ...........dp[first][a[i]]==1 
// dp[x][y]= dp[x-1][y]+dp[x-1][y-1]+ dp[x-1][y-2]+dp[x-1][y-3]....dp[x-1][max(0,y-a[x])]



void solve()
{ 
	cin>>n>>k;
	rep(i,0,n-1)cin>>a[i];
	vector<int> pre(100006),curr(100006);


	for(int x=0;x<n;x++)
	{
		for(int i=0;i<=k;i++)
		{
			if(i==0)dp[x][i]=1;
			else if(x==0)
			{
				if(i<=a[x])dp[x][i]=1;
				else dp[x][i]=0;
			}
       else
       {
       	dp[x][i]= curr[i+1];
       	if(i-a[x]>=1)dp[x][i]-= curr[i-a[x]];

       }
      // cout<<dp[x][i]<<" ";
       dp[x][i]%=mod;

			pre[i+1]= pre[i]+dp[x][i];
		}
		// cout<<endl;
		swap(pre,curr);pre[0]=0;
	}
	


cout<<dp[n-1][k]<<endl;









 return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}

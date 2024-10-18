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
double  dp[3001][3001];
double p[3001];



void solve()
{ 
 cin>>n;
 rep(i,1,n)cin>>p[i];

 dp[0][0]=1;

 rep(i,1,n)
 {
 	rep(j,0,n)
 	{
      if(j) dp[i][j]= dp[i-1][j-1]*p[i]+ dp[i-1][j]*(1-p[i]);
      else dp[i][j]= dp[i-1][j]*(1-p[i]);

      // cout<<dp[i][j]<<" ";
 	}
 	// cout<<endl;
 }

 double ans=0;

 repr(i,n,1)
 {
 	if(2*i>n){ans+= dp[n][i];}
 }

cout<<fixed<<setprecision(10)<<ans<<endl;

return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}
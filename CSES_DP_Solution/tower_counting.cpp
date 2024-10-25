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
// int _BinPow(int mat,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*mat)%m;}a=(a*a)%m;b/=2;}return ans;}

int dp[2][1000009];

void solve()
{
 int n;  cin>>n;
 dp[0][n]=dp[1][n]=1;

 for(int i=n-1;i>=1;i--)
 {
    dp[0][i]= (2*dp[0][i+1]+dp[1][i+1])%mod;
    dp[1][i]= (4*dp[1][i+1]+dp[0][i+1])%mod;

 }

 int ans = (dp[0][1]+dp[1][1])%mod;

cout<<ans<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	cin>>_T;
  while(_T--)solve();
  return 0;  
}

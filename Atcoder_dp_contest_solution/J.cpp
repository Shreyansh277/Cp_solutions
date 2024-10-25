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
double dp[301][301][301];


double f(int n3,int n2,int n1)
{
	if(n3==0 && n2== 0 &&  n1==0)return 0;

	if(abs(dp[n3][n2][n1]+1)>1e-6)return dp[n3][n2][n1];


double t= n1+n2+n3;

double ans = n/t;

if(n3)ans += (f(n3-1,n2+1,n1)*n3)/t;
if(n2)ans += (f(n3,n2-1,n1+1)*n2)/t;
if(n1)ans += (f(n3,n2,n1-1)*n1)/t;

return dp[n3][n2][n1]=ans;


}

void solve()
{ 
	cin>>n;
	int n1=0,n2=0,n3=0;
	rep(i,1,n)
	{
		int x; cin>>x;
		if(x==1)n1++;
		else if(x==2)n2++;
		else n3++;
	}
	memset(dp,-1,sizeof(dp));
	cout<<fixed<<setprecision(16)<<f(n3,n2,n1)<<endl;


return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}

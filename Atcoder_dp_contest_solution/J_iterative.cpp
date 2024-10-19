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




void solve()
{ 
	cin>>n;
	int cnt[4]={0};
	rep(i,1,n)
	{
		int x; cin>>x;
		cnt[x]++;
	}
	
	dp[0][0][0]=0.0;

  for(int three=0;three<=n;three++)
  {
  	for(int two=0;two<=n;two++)
  	{
  		for(int one=0;one<=n;one++)
  		{
  			int zero = n- three-two-one;
  			if(zero==n)continue;

  			if(zero<0)continue;

  			double val = 1.0;

  			if(three>0)val+= ((1.0*three)/n)*dp[three-1][two+1][one];
  			if(two>0)val+= ((1.0*two)/n)*dp[three][two-1][one+1];
  			if(one>0)val+= ((1.0*one)/n)*dp[three][two][one-1]; 

  			val = val/(1-1.0*zero/n);

  			dp[three][two][one]= val;
  		}
  	}
  }






	cout<<fixed<<setprecision(16)<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;


return;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}

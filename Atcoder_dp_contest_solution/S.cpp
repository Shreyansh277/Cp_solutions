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

int d;
string k;
vector<int> num;
int dp[10005][100][2];


int call(int pos,int sum,int f)
{
	if(pos==num.size())
	{
		if(sum==0)return 1;
		return 0;
	}

	if(dp[pos][sum][f]!=-1)return dp[pos][sum][f];

	int LMT=9;
	if(!f)LMT=num[pos];
  
  int res=0;
	for(int dgt=0;dgt<=LMT;dgt++)
	{
		int nsum=(sum+dgt)%d;
		int nf=f;
		if(dgt<LMT)nf=1;
   res= (res+call(pos+1,nsum,nf))%mod;
	}

	return dp[pos][sum][f]=res;
}



void solve()
{
cin>>k>>d;
num.clear();
for(auto c: k)num.pb(c-'0');
memset(dp,-1,sizeof(dp));

int ans = (call(0,0,0)-1+mod)%mod;
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

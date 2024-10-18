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
int dp[100005];
int a[101];


int f(int k)
{
	if(k==0)return 0;

	if(dp[k]!=-1)return dp[k];

	int ans =0;

	rep(i,1,n)
	{
		if(k-a[i]>=0)
		{
			if(f(k-a[i])==0){ans=1; break;}
		}
	}

	return dp[k]= ans;
}



void solve()
{ 
 cin>>n>>k;
 rep(i,1,n)cin>>a[i];
 memset(dp,-1,sizeof(dp));
 

if(f(k))cout<<"First"<<endl;
else cout<<"Second"<<endl;



return;
}







int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;

  while(_T--)solve();
  return 0;  
}

#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repr(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long 
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}
 
int inverse(int a,int m)
{
    return _BinPow(a,m-2,m);
}
 
int sum1r(int a)
{
    a%=mod;
    int ans =  (a*(a+1))%mod;
    ans = (ans*inverse(2,mod))%mod;
    return ans;
}
 
 
void solve()
{
int n,k; cin>>n>>k;
vector<int> v(k+1);    rep(i,1,k)cin>>v[i];

int z = 1<<k;

int ans =0;

rep(i,1,z-1)
{
	int m=1;

	rep(j,0,k-1)
	{
		if((i>>j)&1==1)
		{
			if(m>n/v[j+1])
			{
				m=n+1;
				break;
			}

			m*= v[j+1];
		}
	}

	if(__builtin_popcount(i)%2==1)ans+= n/m;
	else ans-=n/m;
}

cout<<ans<<endl;
 
 
return;
}
 
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _T=1;
  while(_T--)solve();
  return 0;  
}

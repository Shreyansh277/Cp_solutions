
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
 
int inverse(int a)
{
    return _BinPow(a,mod-2,mod);
}
 

 
 int fact[1000001];
 
void solve()
{
int n,ans; cin>>n;

while(n--)
{
	int a,b; cin>>a>>b; 
	int ans = (fact[a]*inverse(fact[b]))%mod;
	(ans *= inverse(fact[a-b]))%=mod;
	cout<<ans<<endl;
}

 
 
return;
}
 
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _T=1;
    fact[0]=1;
    rep(i,1,1000000)
    {
    	fact[i]= (fact[i-1]*i)%mod;
    }
  while(_T--)solve();
  return 0;  
}


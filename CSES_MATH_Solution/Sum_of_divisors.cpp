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

int sum1r(int a)
{
    a%=mod;
    int ans =  (a*(a+1))%mod;
    ans = (ans*inverse(2))%mod;
    return ans;
}


void solve()
{
int n,ans=0; cin>>n;


for(int i=1;i*i<=n;i++)
{
    (ans += (n/i)*i)%=mod;
}
ans%=mod;

int l = sqrt(n);

for(int i= sqrt(n);i>=1;i--)
{
    int r = n/i;
    int sum = (i*sum1r(r))%mod;
    sum= (sum-(i*sum1r(l))%mod+mod)%mod;
    ans += (sum+mod);
    ans%=mod;
    l=r;
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
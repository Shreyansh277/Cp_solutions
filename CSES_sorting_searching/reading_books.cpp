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

// Reading books 



void solve()
{

int ans ,n; cin>>n;
vector<int> v(n),pre(n+1); rep(i,0,n-1)cin>>v[i];
sort(all(v));

rep(i,1,n)
{
	pre[i]=pre[i-1]+v[i-1];
}

if(pre[n-1]<v[n-1])ans = 2*v[n-1];
else ans = pre[n];
cout<<ans<<endl;



return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
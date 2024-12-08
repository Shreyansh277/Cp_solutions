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



// maximum subarray sum 2 

void solve()
{
int n,a,b; cin>>n>>a>>b; 

vector<int> v(n),pre(n+1);


rep(i,0,n-1)
{
	cin>>v[i];
	pre[i+1]=pre[i]+v[i];
}


int l=0,ans=-1e18,temp=0;

multiset<int> mt;


rep(r,a,n)
{
	mt.insert(pre[r-a]);
	if(r>b)mt.erase(mt.find(pre[r-b-1]));
  temp= pre[r]-*mt.begin();
  ans = max(ans ,temp);
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
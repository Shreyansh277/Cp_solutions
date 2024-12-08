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



bool comp(pair<int,int> a,pair<int,int> b)
{
	return a.s<b.s;
}

// sliding window cost 

void solve()
{
int n,k; cin>>n>>k; 

vector<pair<int,int>> v(n);

rep(i,0,n-1)
{
	cin>>v[i].f>>v[i].s;
}

sort(all(v),comp);

multiset<int> mt;

int cnt=0;

rep(i,0,n-1)
{
	if(mt.empty())
	{
		mt.insert(v[i].s*-1);
	}
	else if(mt.lower_bound(v[i].f*-1)!=mt.end())
	{
		mt.erase(mt.lower_bound(v[i].f*-1));
		mt.insert(v[i].s*-1);
	}
	else if(mt.lower_bound(v[i].f*-1)==mt.end() && mt.size()<k)
	{
		mt.insert(v[i].s*-1);
	
	}
	else cnt++;
}

int ans = n-cnt;

cout<<ans<<endl;

return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
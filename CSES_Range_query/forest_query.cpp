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


int pre[1001][1001];

void solve()
{
int n,q; cin>>n>>q;
char c;

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)
	{
		cin>>c;
		pre[i][j]+= pre[i-1][j]+pre[i][j-1]+ (c=='*') -pre[i-1][j-1];
	}
}


while(q--)
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	
	int ans = pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1];
  cout<<ans<<endl;
}




return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
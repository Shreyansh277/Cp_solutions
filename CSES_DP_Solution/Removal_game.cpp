#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repr(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ppb pop_back
#define scd(t) scanf("%d",&t)
#define f first
#define s second
#define mod2 998244353
#define yn() cout<<"NO\n"
#define ys() cout<<"YES\n"
#define all(x) (x).begin(), (x).end()
#define endl "\n"
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> seti;
typedef vector<ll> vli;
 
 
ll arr[5001];
ll dp[5001][5001];
int ans1=2,ans2=0;
 
 
 
ll rec(int s,int e,int turn)
{
	if(s>e)return 0;
 
  if(dp[s][e]!=-1)return dp[s][e];
 
  ll ans =0;
 
  if(turn)
  {
       ans = max(arr[s]+rec(s+1,e,0),arr[e]+rec(s,e-1,0));
  }
  else
  {
      ans = min(rec(s+1,e,1),rec(s,e-1,1));
  }
 
  return dp[s][e]=ans;
 
  // if(s<=n)	
}
 
 
void solve()
{
 
int n; cin>>n;
memset(dp,-1,sizeof(dp));
rep(i,1,n)cin>>arr[i];
 
ll ans = rec(1,n,1);
 
cout<<ans<<endl;
 
return;
}
 
 
 
 
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // memset(dp,-1,sizeof(dp));
	int t=1; 
  while(t--)solve();
 
  return 0;  
}

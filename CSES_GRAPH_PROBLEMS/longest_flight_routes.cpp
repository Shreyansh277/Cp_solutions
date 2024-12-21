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
#define inf 1e18
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}
 
// longest route 
 
void solve()
{
  int n,m; cin>>n>>m;
  vector<int> g[n+1];
  rep(i,1,m)
  {
    int u,v;
    cin>>u>>v;
    g[u].pb(v);
  }
 
  vector<int> dp(n+1,-1);
  dp[n]=1;
  vector<int> maxChild(n+1);
 
  function<int(int)> dfs =[&](int node) -> int{
    if(node ==n)return 1;
    if(dp[node]==-1)
    {
        dp[node]=INT_MIN;
       for(int child: g[node])
       {
        int dist= dfs(child)+1;
        if(dp[node]<dist)
        {
          dp[node]=dist;
          maxChild[node]=child;
        }
       }
    }
 
    return dp[node];
  };
  
  int ans = dfs(1);
 
  if(ans<0)
  {
    cout<<"IMPOSSIBLE\n";
  }
  else
  {
    cout<<ans<<endl;
    int node = 1;
    while(node!=n)
    {
      cout<<node<<" ";
      node= maxChild[node];
    }
    cout<<node<<endl;
  }
  return;
}
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
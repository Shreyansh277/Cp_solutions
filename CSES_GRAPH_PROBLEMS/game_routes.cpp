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
    g[v].pb(u);
  }

  vector<int> dp(n+1,-1);
  dp[1]=1;

  function<int(int)> dfs =[&](int node) -> int{
    if(node ==1)return 1;
    if(dp[node]==-1)
    {
        dp[node]=0;
       for(int child: g[node])
       {
        int cnt= dfs(child);
        (dp[node]+=cnt)%=mod; 
       }
    }

    return dp[node];
  };
  
  int ans = dfs(n);
  cout<<ans<<endl;

  return;
}


int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
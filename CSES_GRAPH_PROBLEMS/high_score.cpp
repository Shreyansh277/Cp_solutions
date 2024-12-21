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

vector<int> vis1,vis2;
vector<vector<int>> e,g1,g2;
void dfs1(int sc)
{
  if(vis1[sc])return;
  vis1[sc]=1;
  for(auto z: g1[sc])dfs1(z);
}

void dfs2(int sc)
{
  if(vis2[sc])return;
  vis2[sc]=1;
  for(auto z: g2[sc])dfs2(z);
}

void solve()
{
  int n,m; cin>>n>>m; vis1.assign(n+1,0); vis2.assign(n+1,0); g1.resize(n+1);g2.resize(n+1);
  
  rep(i,1,m)
  {
   int a,b,c; cin>>a>>b>>c; 
   e.pb({a,b,-c}); g1[a].pb(b); g2[b].pb(a);
  }
  dfs1(1); dfs2(n);

  vector<int> dis(n+1,inf);
  dis[1]=0;
int ans =0;
  rep(i,1,n)
  {
    for(auto z: e)
    {
      int u=z[0];
      int v=z[1];
      int w= z[2];

      if(dis[u]!=inf && dis[v]>dis[u]+w)
      {
        dis[v]=dis[u]+w;
        if(i==n && vis1[v]&& vis2[v])ans=-1;
      }
    }
  }

dis[n]=-dis[n];
if(ans==-1)cout<<-1<<endl;
else cout<<dis[n]<<endl;

return; 
}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
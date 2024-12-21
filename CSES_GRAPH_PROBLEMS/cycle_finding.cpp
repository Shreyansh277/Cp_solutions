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

int n,m; vector<vector<int>> e;
vector<int> dis,par;


void solve()
{
 cin>>n>>m;dis.assign(n+1,inf),par.assign(n+1,0);
 dis[1]=0;
 
  rep(i,1,m)
  {
   int a,b,c; cin>>a>>b>>c; 
   e.pb({a,b,c});
  }

int fo=0;
rep(i,1,n)
{
  fo=0;
  for(auto z: e)
  {
    int u= z[0];
    int v= z[1];
    int w= z[2];

    if(dis[v]>dis[u]+w)
    {
      dis[v]= dis[u]+w;
      par[v]=u;
      fo=v;
    }
  }
  
}

if(!fo){cout<<"NO"<<endl;}
else 
{
  cout<<"YES"<<endl;
  rep(i,1,n){ fo=par[fo];}
  vector<int> cycle;

  for(int x=fo;; x=par[x])
  {
    cycle.pb(x);
    if(fo==x && cycle.size()>1)break;
  }

  reverse(all(cycle));
  for(auto z: cycle)cout<<z<<" ";
}




  

return; 
}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
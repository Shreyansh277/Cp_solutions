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

int n,m,k;
vector<vector<pair<int,int>>> g;
vector<vector<int>> dis;

void djks(int sc)
{
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,sc});
  while(!pq.empty())
  {
    auto p = pq.top();
    pq.pop();
    int u=p.s;
    int d= p.f;
    if(d> dis[u][k-1])continue;

    for(auto z: g[u])
    {
      if(dis[z.f][k-1]>d+z.s)
      {
        dis[z.f][k-1]=d+z.s;
        pq.push({dis[z.f][k-1],z.f});
        sort(all(dis[z.f]));
      }
    }
  }
  return; 
}


void solve()
{
 cin>>n>>m>>k;

 g.resize(n+1);
 dis.assign(n+1,vector<int>(k,inf));
 rep(i,1,m)
 {
  int a,b,c; cin>>a>>b>>c;
  g[a].pb({b,c});
 }

 djks(1);

 for(auto z: dis[n])
 {
  cout<<z<<" ";
 }


return; 
}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
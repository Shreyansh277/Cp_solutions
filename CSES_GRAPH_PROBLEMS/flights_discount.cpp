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

int n,m; vector<vector<pair<int,int>>> g,g2;
vector<int> dis1,dis2;

void djks1(int sc)
{
  dis1[sc]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,sc});
  while(!pq.empty())
  {
    auto p = pq.top();
    pq.pop();
    if(dis1[p.s]<p.f)continue;
    for(auto z: g[p.s])
    {
      if(dis1[z.f]>dis1[p.s]+z.s)
      {
        dis1[z.f]=dis1[p.s]+z.s;
        pq.push({dis1[z.f],z.f});
      }
    }


  }
  return;
}

void djks2(int sc)
{
  dis2[sc]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,sc});
  while(!pq.empty())
  {
    auto p = pq.top();
    pq.pop();
    if(dis2[p.s]<p.f)continue;
    for(auto z: g2[p.s])
    {
      if(dis2[z.f]>dis2[p.s]+z.s)
      {
        dis2[z.f]=dis2[p.s]+z.s;
        pq.push({dis2[z.f],z.f});
      }
    }


  }
  return;
}

void solve()
{
 cin>>n>>m; g.resize(n+1),g2.resize(n+1);
 
  rep(i,1,m)
  {
   int a,b,c; cin>>a>>b>>c; 
  g[a].pb({b,c});
  g2[b].pb({a,c});
  }

  dis1.assign(n+1,inf); dis2.assign(n+1,inf);

  djks1(1);
  djks2(n);

  int ans =inf;

  rep(i,1,n)
  {
    for(auto z: g[i])
    {
      ans = min(ans,dis1[i]+dis2[z.f]+z.s/2);
    }
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
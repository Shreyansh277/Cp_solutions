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

// course schedule 

int n,m; 
vector<int> courses,color;
vector<vector<int>> g;

bool topo(int sc,int par)
{
  if(color[sc])return true;
  color[sc]=1;

  for(auto z: g[sc])
  {
    if(color[z]==0)
      {
        bool t= topo(z,sc);
        if(t)return t;
      }
    else if(color[z]==1)return true;
  }
  courses.pb(sc);
  color[sc]=2;
  return false;
}


void solve()
{
 cin>>n>>m;
 g.resize(n+1);
 color.assign(n+1,0);
 rep(i,1,m)
 {
  int a,b; cin>>a>>b;
  g[a].pb(b);
 }
bool is=false;
rep(i,1,n)
{
  if(color[i]==0)
  {
   is |= topo(i,-1);

  }
}

if(is){cout<<"IMPOSSIBLE"<<endl; return;}

reverse(all(courses));


 for(auto z: courses)
 {
  cout<<z<<" ";
 }
 cout<<endl;


return; 
}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
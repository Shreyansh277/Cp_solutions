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

int n,m,q;

void solve()
{
  cin>>n>>m>>q;

 
 int dis[n+1][n+1];
 rep(i,1,n)rep(j,1,n){dis[i][j]=inf; if(i==j)dis[i][j]=0;}
 rep(i,1,m)
 {
  int a,b,c; cin>>a>>b>>c;
dis[a][b]=min(c,dis[a][b]);
dis[b][a]=min(c,dis[b][a]);

 }

 rep(k,1,n)
 {
  rep(i,1,n)
  {
    rep(j,1,n)
    {
      dis[i][j]= min(dis[i][j],dis[i][k]+dis[k][j]);
    }
  }
 }

 while(q--)
 {
  int a,b; cin>>a>>b;
  int x= dis[a][b];
  if(x==inf)cout<<-1<<endl;
  else cout<<x<<endl;
 }

 

return; 
}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
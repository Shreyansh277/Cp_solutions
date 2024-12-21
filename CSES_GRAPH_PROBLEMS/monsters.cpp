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
#define inf 1e18 +1

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}

char mat[1001][1001];
int n,m;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,+1,-1};


vector<pair<int,int>> f(int i,int j)
{
  vector<pair<int,int>> s;
  rep(k,0,3)
  {
    int ti= i+dx[k];
    int tj = j+dy[k];
    if(ti>=1 && ti<=n && tj>=1 && tj<=m && mat[ti][tj]!='#')s.pb({ti,tj});
  }
  return s;
}

vector<vector<int>> dfsA(vector<pair<int,int>> k)
{
  vector<vector<int>> dis(n+1,vector<int>(m+1,inf));
  queue<pair<int,int>> q;
  for(auto z: k){q.push(z); dis[z.f][z.s]=0;}
  while(!q.empty())
  {
    auto p = q.front(); q.pop();
    for(auto z : f(p.f,p.s))
    {
      if(dis[z.f][z.s]==inf)
      {
        dis[z.f][z.s]=dis[p.f][p.s]+1;
        q.push({z.f,z.s});
      }
    }
  }

  return dis;
}

void solve()
{
  cin>>n>>m;

 vector<pair<int,int>> A,M;
 rep(i,1,n)
 {
  rep(j,1,m)
  {
    cin>>mat[i][j];
    if(mat[i][j]=='A')A.pb({i,j});
    else if(mat[i][j]=='M')M.pb({i,j});
  }
 }

 auto disA= dfsA(A);
 auto disM= dfsA(M);

 int isp=false;
 pair<int,int> sol;
 rep(i,1,n)
 {
  if(mat[i][1]!='#')if(disA[i][1]<disM[i][1]){isp=true; sol={i,1};}
  if(mat[i][m]!='#')if(disA[i][m]<disM[i][m]){isp=true; sol={i,m};}
 }

   rep(j,1,m)
 {
  if(mat[1][j]!='#')if(disA[1][j]<disM[1][j]){isp=true; sol={1,j};}
  if(mat[n][j]!='#')if(disA[n][j]<disM[n][j]){isp=true; sol={n,j};}
 }

 if(isp)
{
  cout<<"YES"<<endl;
  cout<<disA[sol.f][sol.s]<<endl;
  int t= disA[sol.f][sol.s];
  vector<char> path;
  while(t!=0)
  {
    char c;
    for(auto z: f(sol.f,sol.s))
    {
      if(disA[z.f][z.s]==t-1)
      {
        if(sol.f==z.f)
        {
          if(sol.s<z.s)c='R';
          else c='L';
        }
        else
        {
          if(sol.f<z.f)c='D';
          else c='U';
        }

        path.pb(c);
        t--;
        sol=z;
        break;
      }
    }
  }
  reverse(all(path));
  
    for(auto z: path)
    {
      if(z=='L')cout<<'R';
      else if(z=='R')cout<<'L';
      else if(z=='U')cout<<'D';
      else cout<<'U';
    }
    cout<<endl;
}
 else cout<<"NO"<<endl;

return; 

}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
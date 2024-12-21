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

vector<vector<int>> dfsA(pair<int,int> k)
{
  vector<vector<int>> dis(n+1,vector<int>(m+1,inf));
  queue<pair<int,int>> q;
  q.push(k); dis[k.f][k.s]=0;
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

 pair<int,int> A,B;
 rep(i,1,n)
 {
  rep(j,1,m)
  {
    cin>>mat[i][j];
    if(mat[i][j]=='A')A={i,j};
    else if(mat[i][j]=='B')B={i,j};
  }
 }

 auto disA= dfsA(A);
 

 int isp=(disA[B.f][B.s]!=inf);

 if(isp)
{
  cout<<"YES"<<endl;
  cout<<disA[B.f][B.s]<<endl;
  int t= disA[B.f][B.s];
  vector<char> path;
  while(t!=0)
  {
    char c;
    for(auto z: f(B.f,B.s))
    {
      if(disA[z.f][z.s]==t-1)
      {
        if(B.f==z.f)
        {
          if(B.s<z.s)c='R';
          else c='L';
        }
        else
        {
          if(B.f<z.f)c='D';
          else c='U';
        }

        path.pb(c);
        t--;
        B=z;
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
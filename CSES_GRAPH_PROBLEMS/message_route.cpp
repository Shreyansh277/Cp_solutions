#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repr(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
// #define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18+1
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}


// graph algorithms 
// message route

int n,m;
vector<vector<int>>g;
vector<int> dis,parent;


void bfs(int node,int d)
{
   parent[node]=0;
   dis[node]=d;
   queue<int> q;
   q.push(node);
   while(!q.empty())
   {
   	int t = q.front();
   	q.pop();
   	for(auto z: g[t])
   	{
   		if(dis[z]==-1)
   		{
   			q.push(z);
   			dis[z]=dis[t]+1;
   			parent[z]=t;
   		}
   	}
   }

   return;
}
void solve()
{
cin>>n>>m;

g.resize(n+1);
dis.assign(n+1,-1);
parent.assign(n+1,-1);
rep(i,1,m)
{
	int a,b; cin>>a>>b; 
	g[a].pb(b);
	g[b].pb(a);
} 

vector<int> ans;

bfs(1,0);



if(dis[n]==-1)cout<<"IMPOSSIBLE"<<endl;
else 
{
cout<<dis[n]+1<<endl;

vector<int> ans;

int route =n;

while(route!=0)
{
	ans.pb(route);
	route=parent[route];
}
reverse(all(ans));

for(auto z: ans)
{
	cout<<z<<" ";
}

}

return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
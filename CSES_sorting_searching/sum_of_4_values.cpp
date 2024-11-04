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
#define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18+1

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}

void solve()
{
int n,x; cin>>n>>x; vector<int> v(n+1); rep(i,1,n)cin>>v[i];

map<int,pair<int,int>> mp;

rep(i,1,n)
{
	rep(j,i+1,n)
	{
       if(mp.find(x-v[i]-v[j])!=mp.end())
       {
       	cout<<i<<" "<<j<<" "<<mp[x-v[i]-v[j]].f<<" "<<mp[x-v[i]-v[j]].s<<endl;

       	return;
       }
	}

	rep(k,1,i-1)mp[v[i]+v[k]]={i,k};
}

cout<<"IMPOSSIBLE"<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}

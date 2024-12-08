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

// room allocation 

struct ranges
{
	int l,r,in;

	bool operator< (const ranges &other)const
	{
		if(l==other.l)return r<other.r;

		return l<other.l;
	}
};



void solve()
{
int n; cin>>n;

vector<ranges> v(n);

rep(i,0,n-1)
{
	int x,y; cin>>x>>y;
	v[i].l=x;
	v[i].r=y;
	v[i].in=i;
}

sort(all(v));

priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;

vector<int> ans(n);
int room_allocated=0;

rep(i,0,n-1)
{
	if(pq.empty() || pq.top().f>=v[i].l)
	{
		room_allocated++;
		ans[v[i].in]=room_allocated;
		pq.push({v[i].r,room_allocated});
	}
	else
	{
		int x = pq.top().s;
		pq.pop();
		ans[v[i].in]=x;
		pq.push({v[i].r,x});
	}
}

cout<<room_allocated<<endl;
rep(i,0,n-1)
{
	cout<<ans[i]<<" ";
}
return;

}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
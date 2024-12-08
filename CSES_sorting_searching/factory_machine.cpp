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

// factory machines 
vector<int> v;
int n,t;

bool check(int mid)
{
	int temp=0;

	rep(i,0,n-1)
	{
		temp= temp+long(mid/v[i]);
	}

 
 return temp>=t;

}

void solve()
{
 cin>>n>>t;
v.resize(n);
rep(i,0,n-1)cin>>v[i];
int l =0,r=1;

while(!check(r))r*=2;

while(l+1<r)
{
	int mid = (l+r)/2;
	if(check(mid))r=mid;
	else l=mid;


}

cout<<r<<endl;



return;

}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
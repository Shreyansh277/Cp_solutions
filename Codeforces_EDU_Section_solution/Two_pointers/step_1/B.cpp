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
#define int long long 
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}




void solve()
{
int n,m; cin>>n>>m;
vector<int> a(n+1),b(m+1);

rep(i,0,n-1)cin>>a[i];
rep(i,0,m-1)cin>>b[i];

a[n]=2e9; b[m]=2e9;


int i=0,j=0;

while(i<n || j<m)
{
	if(a[i]<b[j])
	{
		i++;
	}
	else {

		 cout<<i<<" ";
		 j++;
	}
}
return;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
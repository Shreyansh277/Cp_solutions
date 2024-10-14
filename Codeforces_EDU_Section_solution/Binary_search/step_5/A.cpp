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



  
int n,k; 
int a[50],b[50];


bool f(int  mid)
{

int ans =0;

rep(i,0,n-1)
{
	if(mid>a[i] && mid<=b[i])
	{
		ans = ans + mid-a[i];
	}
	else if(mid>b[i])
	{
		ans = ans+ b[i]-a[i]+1;
	}
	
}


return ans <=k;
}



void solve()
{
cin>>n>>k;
rep(i,0,n-1)cin>>a[i]>>b[i];

int l=-1e10,r=1e10;
while(l+1<r)
{
	int m = (l+r)/2;
	if(f(m))l=m;
	else r=m;
}

cout<<l<<endl;
}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
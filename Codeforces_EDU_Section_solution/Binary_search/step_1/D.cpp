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
int n,q; cin>>n;
int arr[n+2]; rep(i,1,n)cin>>arr[i];
arr[0]= INT_MIN; arr[n+1]= INT_MAX;
cin>>q;


sort(arr,arr+n+2);
// rep(i,0,n-1)cout<<arr[i]

while(q--)
{
	int l=0,r=n+1,xl,xr,mid;cin>>xl>>xr;

	while(l+1<r)
	{
    int mid = (l+r)/2;
    
    if(xr<arr[mid])r=mid;
    else l= mid;
	}
	

   int ans = r-1;
   l=0,r=n+1;
   while(l+1<r)
	{
    int mid = (l+r)/2;
    
    if(xl<=arr[mid])r=mid;
    else l= mid;
	}
	ans -=l;
	cout<<ans<<" ";

}

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
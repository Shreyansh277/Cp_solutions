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
 
int n,x; cin>>n>>x; vector<int> a(n); rep(i,0,n-1)cin>>a[i];

int ans =0,l=0,temp=0;

rep(r,0,n-1)
{
  temp+=a[r];

  while(temp-a[l]>=x)
  {
  	temp-=a[l];
  	l++;
  }

  if(temp==x)ans++;


} 

cout<<ans<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}

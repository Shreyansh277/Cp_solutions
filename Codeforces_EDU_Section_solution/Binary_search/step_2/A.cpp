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

bool f(int x,int a,int b,int n)
{
	int cnt = (x/a)*(x/b);

	return cnt>=n;
}



void solve()
{
 int a,b,n; cin>>a>>b>>n;

 int l=0,r=1;
 while(!f(r,a,b,n))r*=2;

 while(l+1<r)
 {
 	int m= (l+r)/2;
 	if(f(m,a,b,n))r=m;
 	else l=m;
 }

 cout<<r<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
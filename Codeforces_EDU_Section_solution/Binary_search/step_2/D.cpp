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

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}

int n,m;
vector<int> a,b,c;



bool f(int mid)
{
	int _cnt=0;

	rep(i,0,n-1)
	{
		int t = a[i]*b[i]+c[i];
		int r = mid%t;
		r= min(a[i]*b[i],r);
		int tt = floor(mid/t)*b[i] + (r/a[i]);
		_cnt+= tt;
	}

	return _cnt>=m;
}


void solve()
{

cin>>m>>n; 
a.resize(n); b.resize(n); c.resize(n);
rep(i,0,n-1)cin>>a[i]>>b[i]>>c[i];


 int l=0,r= 1;
 while(!f(r))r*=2;

 // cout<<r<<endl;

 if(m==0)r=0;


 while(l+1<r)
 {
 	int mid = (l+r)/2;
 	if(f(mid))r=mid;
 	else l=mid;
 	
 }

cout<<r<<endl;

int k= m;

	rep(i,0,n-1)
	{
		int t = a[i]*b[i]+c[i];
		int ro = r%t;
		ro= min(a[i]*b[i],ro);
		int tt = floor(r/t)*b[i] + (ro/a[i]);
		cout<<min(k,tt)<<" ";
		k= max(0LL,k-tt);
	}


}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
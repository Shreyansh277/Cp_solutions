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
struct stack
{
	vector<int> s,smn,smx;

	stack(){
	smx.pb(LLONG_MIN);
	smn.pb(LLONG_MAX);
}

	void  push(int x)
	{
		s.pb(x);
		smn.pb(min(smn.back(),x));
		smx.pb(max(smx.back(),x));
	}

	int pop()
	{
		int x = s.back();
		s.ppb();
		smn.ppb();
		smx.ppb();
		return x;
	}

	int mn()
	{
		return smn.back();
	}

	int mx()
	{
		return smx.back();
	}

	bool empty()
	{
		return s.empty();
	}
};

:: stack s1,s2;

bool good()
{
	int mn= min(s2.mn(),s1.mn());
	int mx =max(s2.mx(),s1.mx());

	return mx-mn<=k;
}

void add(int x)
{
	s1.push(x);
}

void remove()
{
	if(s2.empty())
	{
		while(!s1.empty())
		{
       s2.push(s1.pop());
		}
	}

	s2.pop();
}



void solve()
{
 cin>>n>>k;
vector<int> v(n);
rep(i,0,n-1)cin>>v[i];
int ans =0;
int l=0;

rep(r,0,n-1)
{
	add(v[r]);

	while(!good())
	{

		l++;
		remove();
	}
  
  
  ans +=r-l+1;
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
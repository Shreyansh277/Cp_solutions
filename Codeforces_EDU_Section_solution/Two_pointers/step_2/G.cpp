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
	vector<int> s,sgcd;

	stack()
	{
		sgcd.pb(0);
	}

	void  push(int x)
	{
		s.pb(x);
		// cout<<x<<endl;
    sgcd.pb(__gcd(sgcd.back(),x));
	}

	int pop()
	{
		int x = s.back();
		s.ppb();
		sgcd.ppb();
		return x;
	}


int gcd()
{
	return sgcd.back();
}

	bool empty()
	{
		return s.empty();
	}
};

:: stack s1,s2;

bool good()
{
	int g1 = s1.gcd();
	int g2 = s2.gcd();

	return __gcd(g1,g2)==1;
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
 cin>>n;
vector<int> v(n);
rep(i,0,n-1)cin>>v[i];
int ans =1e6;
int l=0;

rep(r,0,n-1)
{
	add(v[r]);
	
	while(good())
	{
		if(good())ans= min(ans,r-l+1);
		l++;
		remove();
		
	}

	
}

if(ans==1e6)ans =-1;
cout<<ans<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
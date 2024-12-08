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



// sliding window cost 

void solve()
{


int n,k; cin>>n>>k; 
int a[n];rep(i,0,n-1)cin>>a[i];

multiset<int> lo_mt,up_mt;
int sum_lo=0,sum_up=0;

if(k==1)
{
	rep(i,1,n)cout<<0<<" ";
	return;
}

rep(i,0,k-2)
{
	if(lo_mt.size()<(k+1)/2){lo_mt.insert(a[i]); sum_lo+=a[i];}
	else
	{
		if(*lo_mt.rbegin()>a[i])
		{
			up_mt.insert(*lo_mt.rbegin());
			sum_up+=*lo_mt.rbegin();
			sum_lo-=*lo_mt.rbegin();
			lo_mt.erase(lo_mt.find(*lo_mt.rbegin()));
			lo_mt.insert(a[i]);
			sum_lo+=a[i];
		}
		else 
		{
			up_mt.insert(a[i]);
			sum_up+=a[i];
		}
	}
}

rep(i,k-1,n-1)
{
	if(*lo_mt.rbegin()>a[i])
	{
			up_mt.insert(*lo_mt.rbegin());
			sum_up+=*lo_mt.rbegin();
			sum_lo-=*lo_mt.rbegin();
			lo_mt.erase(lo_mt.find(*lo_mt.rbegin()));
			lo_mt.insert(a[i]);
			sum_lo+=a[i];
	}
	else 
		{
			up_mt.insert(a[i]);
			sum_up+=a[i];
		}

		int ans = (lo_mt.size()-up_mt.size())*(*lo_mt.rbegin())-sum_lo+sum_up;
		cout<<ans<<" ";

		if(up_mt.find(a[i-k+1])!=up_mt.end())
		{
			up_mt.erase(up_mt.find(a[i-k+1]));
			sum_up-=a[i-k+1];
		}
		else
		{
			lo_mt.erase(lo_mt.find(a[i-k+1]));
			sum_lo-=a[i-k+1];
			lo_mt.insert(*up_mt.begin());
			sum_lo+=*up_mt.begin();
			up_mt.erase(*up_mt.begin());
			sum_up-=*lo_mt.rbegin();
		}
}



return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
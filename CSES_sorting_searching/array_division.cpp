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


int n,k;
int arr[200100];

bool f(int m)
{
	int cnt=1;
	int s=0;

	rep(i,1,n)
	{
		if(s+arr[i]<=m)
		{
			s+=arr[i];
		}
		else if(arr[i]>m)return false;
		else
		{
			s=arr[i];
			cnt++;
		}
	}

	return (cnt<=k);
}

void solve()
{
cin>>n>>k;  rep(i,1,n)cin>>arr[i];

int l=0,r=1e18;

while(l+1<r)
{
	int mid = (l+r)/2;
	if(f(mid))r=mid;
	else l= mid;
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

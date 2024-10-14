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
int n,q; cin>>n>>q;
int arr[n]; rep(i,0,n-1)cin>>arr[i];

// rep(i,0,n-1)cout<<arr[i]

while(q--)
{
	int l=0,r=n-1,x,mid;cin>>x;

	bool t =false;

	while(l<=r)
	{
    int mid = (l+r)/2;
    if(arr[mid]==x){t=true;break;}
    else if(x<arr[mid])r=mid-1;
    else l= mid+1;
	}

	if(t)cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
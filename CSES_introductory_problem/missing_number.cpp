
#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repr(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long 
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}
 
int inverse(int a)
{
    return _BinPow(a,mod-2,mod);
}
 

 
// weird algorithms
 
void solve()
{
int n,x; cin>>n;

int ans =0; 
rep(i,1,n)
{
	if(i!=1){cin>>x;ans^=x;}
	ans^=i;

}
cout<<ans<<endl;
 
 
return;
}
 
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _T=1;
  while(_T--)solve();
  return 0;  
}


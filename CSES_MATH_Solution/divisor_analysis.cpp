
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
 
int inverse(int a,int m)
{
    return _BinPow(a,m-2,m);
}
 
int sum1r(int a)
{
    a%=mod;
    int ans =  (a*(a+1))%mod;
    ans = (ans*inverse(2,mod))%mod;
    return ans;
}
 
 
void solve()
{
int n,ans=0; cin>>n;
int no_of_divisor=1;
 
vector<int> a(n+1),b(n+1);
 
rep(i,1,n)
{
   cin>>a[i]>>b[i];
}

// no of divisors 
rep(i,1,n)
{
	(no_of_divisor*= (b[i]+1))%=mod;
}

cout<<no_of_divisor<<" ";

// sum of divisors
int pi=1;
rep(i,1,n)
{
	int numerator = (_BinPow(a[i],b[i]+1,mod)-1+mod)%mod;
	int dinominator = _BinPow(a[i]-1,mod-2,mod);
	(pi*= (numerator*dinominator%mod))%=mod;
}

cout<<pi<<" ";
 
// product of divisors
pi=1;
int mu=1;
rep(i,1,n)
{
    int t = _BinPow(a[i],b[i]*(b[i]+1)/2,mod);
    mu = (_BinPow(mu,b[i]+1,mod)*_BinPow(t,pi,mod))%mod;
    (pi *= (b[i]+1))%=(mod-1);
}
 
cout<<mu<<endl;
 
 
return;
}
 
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _T=1;
  while(_T--)solve();
  return 0;  
}


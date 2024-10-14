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

int arr[10001];
double n,x,y;

bool f(double m)
{

double ans = m*m + sqrt(m);


   

   return ans>=n; 
}



void solve()
{
 cin>>n; 

 double l=0,r= 1e5;


for(int i=0;i<100;i++)
{
	double m = (l+r)/2;
	if(f(m))r=m;
	else l=m;
}

cout<<fixed<<setprecision(15)<<r<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
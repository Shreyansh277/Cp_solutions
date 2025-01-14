// unoptimise version of frog jump problem giving tle at the time of submission 
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
#define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}

// frog jump3 but tle not optimise 


void solve()
{
    
  int n,c; cin>>n>>c;
  int height[n+1],dp[n+1];
  memset(dp,-1,sizeof(dp));
  rep(i,1,n)
  {
    cin>>height[i];
  }
   dp[1]=0;
  function<int(int)> f= [&](int level)->int
  {
   if(level<1)return 0;
   if(dp[level]==-1)
   {
     int ans =inf;
     rep(i,1,level-1)
     {
      ans =min(f(i)+(height[level]-height[i])*(height[level]-height[i])+c,ans);
     }

     dp[level]=ans;
   }

   return dp[level];
  };

  int ans = f(n);
  cout<<ans<<endl;

  
  return;
}


int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
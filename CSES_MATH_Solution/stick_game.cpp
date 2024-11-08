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
     

 int dp[1000001];
 int p[101];
 int n,k;

    
  int f(int i)
  {

    if(i==0)return 0;
  	if(dp[i]!=-1)return dp[i];
  	
    
    int ans=0;

    rep(j,1 ,k)
    {
    	if(i>=p[j])
    	{
    		if(f(i-p[j])==0){ans=1; break;}
    	}
    }


    return dp[i]=ans;


  }


     
     
    void solve()
    {
     
    int ans; cin>>n>>k;
    rep(i,1,k)cin>>p[i];
    memset(dp,-1,sizeof(dp));

    rep(i,1,n)
    {
    	ans = f(i);
    	if(ans)cout<<"W";
    	else cout<<"L";
    }
     
    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1; 
      while(_T--)solve();
      return 0;  
    }
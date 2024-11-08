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
     
    
  int f(int n,int k)
  {

  	if(n==1)return 1;
  	if(k<=(n+1)/2)
  	{
  		if(2*k>n)return 1;
  		return 2*k;
  	}

  	int temp = f(n/2,k-(n+1)/2);

  	if(n%2)return 2*temp+1;
  	else return (2*temp-1+n)%n;
  }


     
     
    void solve()
    {
     
    int n,k,ans; cin>>n>>k;

    ans = f(n,k);
    cout<<ans<<endl;
     
    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1; 
    	cin>>_T;
      while(_T--)solve();
      return 0;  
    }
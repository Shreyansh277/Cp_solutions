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
     
int n,sum;
vector<int> v; 


	int f(void)
	{
   int k= INT_MAX;

   rep(i,0,(1<<(n-1))-1)
   {
   	 int t=0;
   	 rep(j,0,18)
   	 {
   	 	if((i>>j)&1)t+=v[j];
   	 }

   	 k= min(k,abs(sum-2*t));
   }

   return k;
	}






    void solve()
    {
      cin>>n; v.resize(n);

      rep(i,0,n-1){cin>>v[i]; sum+=v[i];}

      int r = f();

      cout<<r<<endl;

    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1;
      while(_T--)solve();
      return 0;  
    }
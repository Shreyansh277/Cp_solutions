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
     
    vector<pair<int,int>> ans;

    void f(int no,int a,int b,int m)
    {
    	if(no==1){ans.pb({a,b}); return;}
    	f(no-1,a,m,b);
    	ans.pb({a,b});
    	f(no-1,m,b,a);
    }
     
    void solve()
    {
      int n; cin>>n;

      f(n,1,3,2);

      cout<<ans.size()<<endl;
      for(auto z: ans)cout<<z.f<<" "<<z.s<<endl;

    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1;
      while(_T--)solve();
      return 0;  
    }
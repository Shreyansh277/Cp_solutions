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
     
     
    void solve()
    {
     int n; string s; cin>>s; n=s.length();
     vector<char> st;   for(auto z:s)st.pb(z); sort(all(st));
     vector<vector<char>> sd;

     do
     {
     	 sd.pb(st);
     	
     }while(next_permutation(all(st)));

     cout<<sd.size()<<endl;

     for(auto z: sd)
     {
     	for(auto x: z)cout<<x;
     		cout<<endl;
     }



    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1;
      while(_T--)solve();
      return 0;  
    }
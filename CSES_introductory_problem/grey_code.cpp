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
     
     // build grey code of length n using the grey code of length n-1 constructively build your solution
     
    void solve()
    {
     int n; cin>>n; 
     vector<string> curr,pr;
     pr= {"0","1"};

     rep(i,2,n)
     {
     	for(auto z: pr)curr.pb("0"+z);
     	for(int i=pr.size()-1;i>=0;i--)curr.pb("1"+pr[i]);

     		swap(curr,pr);
     	curr.clear();
     }

     for(auto z: pr)cout<<z<<endl;

    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1;
      while(_T--)solve();
      return 0;  
    }
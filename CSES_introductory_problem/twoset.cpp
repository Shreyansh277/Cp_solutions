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
     int n,ans; cin>>n;
     ans = n*(n+1)/2;

     int s=0;

     if(ans%2==0)
     {
     	cout<<"YES"<<endl;
     	 int k=ans/2;int z=0;
     	 vector<int> v;
     	 repr(i,n,1)
     	 {
     	 	if(k-i>0)k-=i;
     	 	else break;
     	 	v.pb(i);
     	 	z++;
     	 }

     	 if(k){v.pb(k),z++;}
     	 cout<<z<<endl;
     	 for(auto z: v)cout<<z<<" ";
     	 	cout<<endl;
     	 	cout<<n-z<<endl;

     	 rep(i,1,n-z+1)
     	 {
     	 	if(i==k)continue;
     	 	cout<<i<<" ";
     	 }
     }
     else cout<<"NO";
     
     

    }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1;
      while(_T--)solve();
      return 0;  
    }
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
     int n; string s; cin>>s; n= s.length();
     vector<char> st(n+1,'A');
     vector<int>v(26); rep(i,0,n-1)v[s[i]-'A']++;

     int odd=0;

     rep(i,0,25){if(v[i]%2)odd++;}

     if(odd>1)
     {
     	cout<<"NO SOLUTION"<<endl;
     }
     else
     {
     	int l=1,r=n;
     	rep(i,0,25)
     	{
     		if(v[i]%2==1){st[(n+1)/2]= ('A'+i); v[i]--;}
     		while(v[i])
     		{
     			v[i]-=2;
     			st[l]+=i; st[r]+=i; l++; r--;
     		}
     	}



     	rep(i,1,n)cout<<st[i];
     	cout<<endl;
     }



      }
     
     
     
    int32_t main(){
      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    	int _T=1;
      while(_T--)solve();
      return 0;  
    }
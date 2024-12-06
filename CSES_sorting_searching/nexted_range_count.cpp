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
// #define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18+1
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}


// policy based data structure 
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;
  
// Declaring ordered_set 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_multiset;


// Nexted range count

struct range
{
	int l,r,in;

	bool operator<(const range& other) const
	{
    if(l==other.l)return r>other.r;

    return l<other.l;
	}
};


void solve()
{
int n; cin>>n;

vector<range> v(n);
ordered_multiset mt;

rep(i,0,n-1)
{
  cin>>v[i].l>>v[i].r;
  v[i].in=i;
}

sort(all(v));

int ans[2][n];
memset(ans,0,sizeof(ans));

repr(i,n-1,0)
{
   if(!mt.empty())
   {
   	ans[0][v[i].in]=mt.order_of_key(v[i].r+1);
   }

mt.insert(v[i].r);
}

mt.clear();

rep(i,0,n-1)
{
   if(!mt.empty())
   {
   	ans[1][v[i].in]=mt.size()-mt.order_of_key(v[i].r);
   }

   mt.insert(v[i].r);
}


rep(i,0,n-1)
{
   cout<<ans[0][i]<<" ";	
}
cout<<endl;

rep(i,0,n-1)
{
	cout<<ans[1][i]<<" ";
}

return;

}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
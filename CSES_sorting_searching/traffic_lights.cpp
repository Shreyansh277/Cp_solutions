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

// 

void solve()
{
int n,x; cin>>x>>n;
set<int> a;
multiset<int> mt;
a.insert(0); a.insert(x);  mt.insert(x);

int p;
rep(i,1,n)
{
  cin>>p;
  a.insert(p);
  auto it =  a.find(p);
  int nextelement = *next(it);
  int prevelement= *prev(it);

  auto at = mt.find(nextelement-prevelement);
  mt.erase(at);
  mt.insert(nextelement-p);
  mt.insert(p-prevelement);

  cout<<(*mt.rbegin())<<" ";
}
return;

}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
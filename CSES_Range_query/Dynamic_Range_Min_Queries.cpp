#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repr(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long int
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007
#define inf 1e18
 
// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}
 
class segTree
{
  public: vector<int> seg;
  segTree(int n)
  {
    seg.resize(4*n+1);
  }
  
  // function to build the segment tree which store the min value of the range 
  void build(int ind,int low,int high,int arr[])
  {
    if(low==high)
    {
      seg[ind]=arr[low];
      return;
    }
 
    int mid= (low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    return;
  }
  // function to find the min value of a given range in an array
  int query(int ind,int low,int high,int l,int r)
  {
    // No overlap mode [l r] low high [l r]
    if(r<low || l>high)
    {
      return INT_MAX;
    }
 
    // complete overlap
    if(high<=r && low>=l)
    {
      return seg[ind];
    }
 
    // partial overlap
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right =query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
  }
 
  // function to point update in array and change the segTree accordingly
  void update(int ind,int low,int high,int i,int val)
  {
    // found the index
    if(low ==high)
    {
      seg[ind]=val;
      return;
    }
    
    // searching the index
    int mid = (low+high)/2;
    if(i<=mid)update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
 
    seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);
    return;
  }
 
};
 
void solve()
{
 
  int n,q; cin>>n>>q;
  int arr[n]; 
  rep(i,0,n-1)cin>>arr[i];
  segTree s1(n);
  s1.build(0,0,n-1,arr);
 
  while(q--)
  {
    int t=1,a,b; cin>>t>>a>>b;
    if(t==2)
    {
      a--; b--;
      cout<<s1.query(0,0,n-1,a,b)<<endl;
    }
    else
    {
      a--;
      s1.update(0,0,n-1,a,b);
      arr[a]=b;
    }
 
  }
 
 
 
 
  
  return;
}
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
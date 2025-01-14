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



// class of segment tree with lazy propagation
class ST
{
	public :
	vector<int> seg,lazy;
  ST(int n)
  {
  	seg.resize(4*n+1);
  	lazy.resize(4*n+1);
  }
  
  // function to build the segtree 
  void build(int ind,int low,int high,int arr[])
  {
  	if(low==high)
  	{
  		seg[ind]=arr[low];
  		return;
  	}
    
    int mid = (low+high)>>1;
  	build(2*ind+1,low,mid,arr);
  	build(2*ind+2,mid+1,high,arr);

  	seg[ind]= seg[2*ind+1]+seg[2*ind+2];
  	return;
  }
  
  // function to update the segTree
  void update(int ind ,int low,int high,int l, int r,int val)
  {
    // update the lazy node 
      if(lazy[ind]!=0)
    {
      seg[ind]+=(high-low+1)*lazy[ind];
      if(low!=high){
      lazy[2*ind+1]+=lazy[ind];
      lazy[2*ind+2]+=lazy[ind];
    }
      lazy[ind]=0;

    }


    // No overlap 
    if(l>high || r<low)
    {
    	return;
    }

    // complete overlap
    if(l<=low && r>=high)
    {
    	seg[ind]+= (high-low+1)*val;
    	if(low!=high)
    	{
    		lazy[2*ind+1]+=val;
    		lazy[2*ind+2]+=val;
    	}
    	return;
    }


    // partial overlap 
    int mid = (low+high)>>1;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);

    seg[ind]= seg[2*ind+1]+seg[2*ind+2];
    return;
  }

  // query function of seg tree
  int query(int ind,int low,int high,int l,int r)
  {
  	// update the lazy node 
      if(lazy[ind]!=0)
    {
      seg[ind]+=(high-low+1)*lazy[ind];
      if(low!=high){
      lazy[2*ind+1]+=lazy[ind];
      lazy[2*ind+2]+=lazy[ind];
    }
      lazy[ind]=0;

    }


        // No overlap 
    if(l>high || r<low)
    {
    	return 0;
    }

    // complete overlap
    if(l<=low && r>=high)
    {
    	return seg[ind];
    }

    // partial overlap
    int mid = (low+high)>>1;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);

    return (left+right);


  }
};

void solve()
{
int n,q; cin>>n>>q;
int arr[n]; rep(i,0,n-1)cin>>arr[i];
ST st(n);
st.build(0,0,n-1,arr);

// for(int z: st.seg)cout<<z<<" ";

while(q--)
{
	int t; cin>>t;
	if(t==1)
	{
		int a,b,val; cin>>a>>b>>val; a--; b--;
		st.update(0,0,n-1,a,b,val);
	}
	else
	{
		int k; cin>>k; k--;
		cout<<st.query(0,0,n-1,k,k)<<endl;
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
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

// list romoval 


// class of segment tree to find the index of the left most hotel which has enough rooms
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
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    return;
  }
  // function to find the min value of a given range in an array
  int query(int ind,int low,int high,int l,int r)
  {
    //  no overlap
    if(l>high || low>r)
    {
      return 0;
    }

    // complete overlap
    if(l<=low && r>=high)return seg[ind];
 
    // partial overlap
    int mid = (low+high)>>1;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return left+right;
  }
 
  // function to point update in array and change the segTree accordingly
  void update(int ind,int low,int high,int i,int val)
  {
    // found the point
    if(low ==high)
    {
      seg[ind]=val;
      return;
    }
    
    // searching the index
    int mid = (low+high)/2;
    if(i<=mid)update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
 
    seg[ind]= seg[2*ind+1]+seg[2*ind+2];
    return;
  }
 
};



void solve()
{
 int listSize;
 cin>>listSize;
 int list[listSize];
 int isPresent[listSize];
 for(int i=0;i<listSize;i++){cin>>list[i]; isPresent[i]=1;}
 segTree s1(listSize);
 s1.build(0,0,listSize-1,isPresent);
 int query = listSize;

 
 while(query--)
 {
 	int index; cin>>index;
 	int l=0,r=listSize-1;
 	while(l<r+1)
 	{
 		int mid = (l+r)>>1;
 		int x=s1.query(0,0,listSize-1,0,mid);
 		if(x>index)r=mid-1;
 		else if(x==index && isPresent[mid]==0)r=mid-1;
 		else l=mid+1;
 	}
 	isPresent[r]=0;
 	s1.update(0,0,listSize-1,r,0);
  cout<<list[r]<<" ";
 }

return;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
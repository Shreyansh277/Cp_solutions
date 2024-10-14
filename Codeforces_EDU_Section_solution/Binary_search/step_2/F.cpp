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
#define int long long 
typedef vector<int> vi;
#define mod2 998244353
#define mod 1000000007

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}


vector<int> arr;
string t,p;
int len;

bool f(int m)
{
    vector<bool> v(len+1,false);    rep(i,1,m)v[arr[i]]=true;



int k = p.size();
int i=0,j=0;

   while(i<len && j<k)
   {
    if(v[i+1])i++;
    else if(p[j]==t[i]){i++;j++;}
    else i++;

   }

   return j==k;

}






void solve()
{
     cin>>t>>p;
    len = t.size();
    arr.resize(len+1);
    rep(i,1,len)cin>>arr[i];

int l=0,r=len;
while(l+1<r)
{
    int m = (l+r)/2;
    if(f(m))l=m;
    else r =m;

    // cout<<l<<" "<<r<<endl;
}

cout<<l<<endl;
}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _T=1;
  while(_T--)solve();
  return 0;  
}
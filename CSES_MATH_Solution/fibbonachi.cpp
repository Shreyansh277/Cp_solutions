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



vector<vector<int>> matmul(vector<vector<int>> a,vector<vector<int>> b)
{
  vector<vector<int>> res={{0,0},{0,0}};
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      for(int k=0;k<2;k++)
      {
        (res[i][j]+= a[i][k]*b[k][j])%=mod;
      }
    }
  }
  return res;
}

vector<vector<int>>  binmatpow(vector<vector<int>> a,int pow)
{
  vector<vector<int>> res= {{1,0},{0,1}};

  while(pow)
  {
    if(pow%2)res =matmul(res,a);
   a = matmul(a,a);
    pow/=2;
  }

  return res;

}



void solve()
{

int n; cin>>n;

if(n==0){cout<<0<<endl; return;}
vector<vector<int>> ans = binmatpow({{1,1},{1,0}},n-1);

cout<<ans[0][0]<<endl;



}




int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int _T=1;
  while(_T--)solve();
  return 0;  
}
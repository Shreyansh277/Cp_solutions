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

char mat[9][9];
vector<int> queen(9);
int ans;

int check(int a,int b)
{
	if(mat[b][a]=='.')
	{
		rep(i,1,b-1)
		{
			if(queen[i]==a || abs(i-b)==abs(queen[i]-a))return 0;
		}
	}
	else return 0;

	return 1;
}

void fun(int level)
{
	if(level==8){ans++; return;}

	rep(i,1,8)
	{
		if(check(i,level+1))
		{
			queen[level+1]=i;
			fun(level+1);
			queen[level+1]=0;
		}
	}

	return;
}

void solve()
{
  rep(i,1,8)rep(j,1,8)cin>>mat[i][j];

  fun(0);
  cout<<ans<<endl;
}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
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

// collectiing numbers 

void solve()
{
int n,m; cin>>n>>m;
vector<int> a(n+1),pos(n+2);

rep(i,1,n)
{
	cin>>a[i]; pos[a[i]]=i;
}

int p=n+1,ans=0;
rep(i,1,n)
{
	if(pos[i]<p)
	{
	 ans++;
	}
	p=pos[i];
}


pos[0]=0; pos[n+1]=n+1;



rep(i,1,m)
{
	int x,y; cin>>x>>y;

if(abs(a[x]-a[y])==1)
{
	if(a[x]<a[y])
	{
		if(pos[a[x]]<pos[a[x]-1])ans--;
		if(pos[a[y]]>pos[a[y]+1])ans--;
		if(pos[a[x]]>pos[a[y]+1])ans++;
		if(pos[a[y]]<pos[a[x]-1])ans++;

		if(pos[a[x]]<pos[a[y]])ans++;
		else ans--;
	}
	else
	{

		if(pos[a[y]]<pos[a[y]-1])ans--;
		if(pos[a[x]]>pos[a[x]+1])ans--;
		if(pos[a[y]]>pos[a[x]+1])ans++;
		if(pos[a[x]]<pos[a[y]-1])ans++;

		if(pos[a[y]]<pos[a[x]])ans++;
		else ans--;

	}
}
else
{
	if(pos[a[x]]<pos[a[x]-1])ans--;
	if(pos[a[x]]>pos[a[x]+1])ans--;
	if(pos[a[x]]<pos[a[y]-1])ans++;
	if(pos[a[x]]>pos[a[y]+1])ans++;

	if(pos[a[y]]<pos[a[y]-1])ans--;
	if(pos[a[y]]>pos[a[y]+1])ans--;
	if(pos[a[y]]<pos[a[x]-1])ans++;
	if(pos[a[y]]>pos[a[x]+1])ans++;
}

swap(pos[a[x]],pos[a[y]]);
swap(a[x],a[y]);
cout<<ans<<endl;

}



return;

}
 
 
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1;
  while(_T--)solve();
  return 0;  
}
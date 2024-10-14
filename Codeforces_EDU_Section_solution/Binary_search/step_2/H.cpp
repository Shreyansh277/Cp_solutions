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

// Functions
int _BinPow(int a,int b,int m){int ans =1;while(b){if(b%2){ans=(ans*a)%m;}a=(a*a)%m;b/=2;}return ans;}

string s; int nb,ns,nc,pb,ps,pc,rubal;

int v[3];

bool f(int m)
{
  int a = m*v[0];
  int b= v[1]*m;
  int c = v[2]*m;

  a= max(0LL,a-nb);
  b= max(0LL,b-ns);
  c= max(0LL,c-nc);

  int p = a*pb+b*ps+c*pc;

  return p<=rubal;
}

void solve()
{
 cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>rubal; 

 for(auto x: s)
 {
 	if(x=='B')v[0]++;
 	else if(x=='S')v[1]++;
 	else v[2]++;
 }



 int l=0,r= 1;
 while(f(r))r*=2;


 while(l+1<r)
 {
 	int m = (l+r)/2;
 	if(f(m))l=m;
 	else r=m;
 	
 }

cout<<l<<endl;

}



int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _T=1; 
	// cin>>_T;
  while(_T--)solve();
  return 0;  
}
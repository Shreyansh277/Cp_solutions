#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define repr(x, y, z) for (int x = y; x >= z; x--)
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
int _BinPow(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}

int n, m;
vector<int> parent, sz, mx;

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (a < b)
            swap(a, b);
        parent[a] = b;
        mx[b] = max(mx[b], mx[a]);
        sz[b] += sz[a];
    }

    return;
}

void solve()
{

    cin >> n >> m;
    parent.resize(n + 1);
    sz.resize(n + 1);
    mx.resize(n + 1);
    rep(i, 1, n)
    {
        parent[i] = i;
        sz[i]++;
        mx[i] = i;
    }

    string s;
    int x, y;
    while (m--)
    {
        cin >> s >> x;
        if (s == "union")
        {
            cin >> y;
            Union(x, y);
        }
        else
        {
            int a = find(x);
            cout << a << " " << mx[a] << " " << sz[a] << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _T = 1;
    // cin>>_T;
    while (_T--)
        solve();
    return 0;
}
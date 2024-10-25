#include<bits/stdc++.h>
using namespace std;

int const N= 1000000;
bool prime[N+1];

int main()
{
    int n;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;

    for(int i=2; i*i<=n;i++)
    {
        if(!prime[i])continue;

        for(int j=i*i;j<=n;j+=i)prime[j]=false;
    }
}
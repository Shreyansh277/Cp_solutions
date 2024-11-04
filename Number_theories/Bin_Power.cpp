int _Binpow(int a,int b,int mod)
{
    int ans =1;
    while(b)
    {
        if(b%2)ans = (1LL*ans*a)%mod;
        a= (1LL*a*a)%mod;
        b/=2;
    }
    return ans;

}
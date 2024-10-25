#include<bits/stdc++.h>
using namespace std;


// gcd(a,b)= gcd(a-b,b)
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
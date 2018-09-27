#include <bits/stdc++.h>

using namespace std;
bool prime( int n )
{
    if( n < 2 )
        return false;
    for( int i =  2 ; i*i <= n ; i++ )
        if( n%i == 0 )
            return false;
    return true;
}

vector<int> factors(int n )
{
    vector <int> f;
    for( int x = 2 ; x*x <=  n ; x++ )
    {
        while( n%x == 0 )
        {
            f.push_back(x);
            n/=x;
        }
    }

    if( n > 1 )
    {
        f.push_back(n);
    }
    return f;
}

int p[100000]={0};
bool sieve_of_eratosthenes( int n )
{
    if( n < 2 )
        return false;
    for( int x  = 2 ; x <=  n ; x++ )
    {
        if( p[x] ) // not prime
            continue;
        for( int u = 2*x ; u <= n ; u+=x )
        {
            p[u] = x; // not prime, x is prime factor of u
        }
    }

    if( p[n] ) // not prime
        return false;
    else        // prime
        return true;
}
// calculate x^n mod m
int big_mod( int x, int n, int m )
{
    if( n == 0 )
        return 1;
    if( n == 1 )
        return x%m;
    if( (n&1) == 1 ) // n is odd
    {
        return ( big_mod(x, n-1, m) * (x%m) )%m;
    }
    else
    {
        int u = big_mod(x, n/2, m);
        u = (u*u)%m;
        return u;
    }
}

int main()
{
    cout << big_mod(2374859, 3029382, 36123);
    int n;
    cin >> n;
    // bool ans = prime(n);
    bool p = sieve_of_eratosthenes(n);
    if( p )
        cout << "prime\n";
    else
        cout << "not prime\n";

    cout << "factors: ";
    vector <int> fa;
    fa = factors(n);
    for( unsigned int i = 0 ; i < fa.size() ; i++ )
        cout << fa[i] << " ";
    return 0;
}

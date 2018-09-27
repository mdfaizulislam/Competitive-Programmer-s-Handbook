#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
// minimum no of coin required to make amount n;
// coins 1, 4, 6;
int coin[1000];
int min(int a, int b, int c)
{
    int t;
    t =(a<b)?a:b;
    return (c<t)?c:t;
}
void coin_change( int x)
{
    int n=0;
    while( n <= x )
    {
        if( n <= 1 )
        {              // if n == 0, no change require
            coin[n]=n;
            n++;
            continue; // if n ==  1 , only 1 change required
        }

        if( n - 1 >= 0 )
            coin[n]=coin[n-1]+1;
        if( n -4 >= 0)
            coin[n]=(coin[n-1]+1 < coin[n-4]+1)?coin[n-1]+1:coin[n-4]+1;
        if( n-6 >= 0)
            coin[n]=min(coin[n-1]+1, coin[n-4]+1, coin[n-6]+1);
        n++;
    }
    //for( int i = 0  ; i <= x ; i++)
      //  cout << i << " = " << coin[i] <<"\n";
      cout << "first way " << coin[x];
}

int d[MAX] = {0};
int coins[] = {1, 4, 6};
int Num_of_coins = 3;
int coinChange_AnotherWay(int x)
{
    d[0] = 0; // for value 0, no coin is needed
    for( int i = 1; i <= x; i++ )
    {
        int u = 1e7;
        for( int j = 0 ; j < Num_of_coins; j++ )
        {
            if( i - coins[j] < 0 )
                continue;
            u = min(u, d[i-coins[j]]+1);
        }
        d[i]=u;
    }
    return d[x];
}

// sometimes we are said to find out total number of solutions.
// Now we don't minimize or maximize
// the count rather we sum up all the ways
int ways[MAX] = {0};
int m = 1e7+7; // modulo
int total_ways(int x)
{
    ways[0] = 1;
    for( int i = 1 ; i <= x ; i++ )
    {
        for( int j = 0 ; j < Num_of_coins; j++ )
        {
            if( i - coins[j] < 0 )
                continue;
            ways[i]+=ways[i-coins[j]];
            //cout << ways[i] << " ";
            // ways[i]%=m;
        }
    }

    return ways[x];
    // sometimes total num of ways is so large, we are said to
    // return the number modulo m
    // so we do modulo m after each addition ways[i]%=m;
}
int main()
{
    int n;
    cin >> n;
    coin_change(n);
    cout << "\nsecond way " << coinChange_AnotherWay(n);
    cout << "\nWays " << total_ways(n);
    return 0;
}

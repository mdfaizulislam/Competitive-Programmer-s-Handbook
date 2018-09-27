#include <bits/stdc++.h>

/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.

*/
using namespace std;
int min( int a, int b, int c)
{
    return min(min(a,b),c);
}
int editString( string str1, string str2, int m, int n)
{
    if( m == 0 )
        return n;
    if( n == 0 )
        return m;
    if( str1[m-1] == str2[n-1] )
    {
        return editString(str1, str2, m-1, n-1);
    }

    return 1+ min(editString(str1, str2, m, n-1), editString(str1, str2, m-1, n), editString(str1, str2, m-1, n-1));
}

int editStringDP(string str1, string str2, int m, int n)
{
    int dp[m+1][n+1];
    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n; j++ )
        {
            if( i == 0 )
                dp[i][j]=j;
            else if( j == 0 )
                dp[i][j]=i;
            else if( str1[i-1] == str2[j-1] )
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }
    return dp[m-1][n-1];
}
int main()
{
    string a = "sunday";
    string b = "saturday";
    int ans  = editStringDP(a, b,a.length(), b.length());
    cout << ans;
    return 0;
}

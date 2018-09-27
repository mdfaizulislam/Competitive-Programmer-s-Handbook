#include <iostream>

using namespace std;
/*
 given a integer n, you have to make k-th bit of the integer to 1 and return resultant n;
we can do this, first take a variable of value 1 and left shift k-1 , at last, perform or operation with n
*/
int on( int n , int k )
{
    int x=1;
    x = x << (k-1);
    n = n|x;
    return n;
}

/*
given a integer n, you have to make k-th bit of the integer to 0 and return resultant n;
1st, left shift k-1  and perform xor operation
here, k -th bit can be 0, so before performing operation we have to check the k-th bit if it is either 1 or 0, if it is 0,
we have to do nothing.
*/
int check(int n, int k)
{
    int x=1;
    x = x << (k-1);
    n = n&x;
    return n;
}
int off( int n, int k)
{
    if( check(n,k) )
    {
        int x = 1;
        x = x << (k-1);
        n = n^x;
        return n;
    }
    return n;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << "bit on "<<on(n,k) <<"\n";
    cin >> n >> k;
    cout <<"Bit off "<<off(n,k);
    return 0;
}

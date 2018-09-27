/*
Motivation Problem: Given an array having N integers, find the contiguous subarray having sum as great as possible,
but not greater than M. For details on the statement, refer the problem link here https://www.spoj.com/problems/HOTELS/

Constraints: Array can have at most 10^5 elements and each number will be non-negative and can be as big as 10^9.
*/
// https://tp-iiita.quora.com/The-Two-Pointer-Algorithm
#include <iostream>
#include <malloc.h>
using namespace std;

int max( int a, int b)
{

    return a>b?a:b;
}
// two pointer method
int cu_sum_greater_not_M( int *arr, int n, int M)
{
    int leftIndex=0;
    int rightIndex=0;
    int cum_sum=0, ans=0;
    while( rightIndex < n ){

        cum_sum+=arr[rightIndex];
        while( cum_sum > M){
            cum_sum-=arr[leftIndex];
            leftIndex++;
        }

        ans = max(ans,cum_sum);
        rightIndex++;
    }

    return ans;
}
int main()
{
    /*
    int arr[]={2, 1, 3, 4, 5};
    int n = sizeof arr/sizeof arr[0];
    int M = 12;
    */
    int arr[100000];
    int n, M;
    cin >> n >> M;
    for( int i = 0 ; i < n ; i++ )
        cin >> arr[i];
    int ans = cu_sum_greater_not_M(arr, n, M);

    cout << ans;
    /*
    if( ans == 0 )
        cout << "No such sub array";
    else
        cout << ans;
    */
    return 0;
}

/*
Motivation Problem: Given a sorted array A, having N integers. You need to find any pair(i,j) having sum as given number X.

Constraints: Array A contains about 10^5 integers with each having values around 10^9.
https://tp-iiita.quora.com/The-Two-Pointer-Algorithm
*/
#include <iostream>
#include <malloc.h>
using namespace std;

int * pair_sum_equals_to_k(int *arr, int n, int k)
{
    int left = 0;
    int right = n-1;
    while( left < right)
    {
        if( arr[left] + arr[right] == k )
            {
                int *index;
                index = (int *)malloc( 2*sizeof(int));
                index[0]=left;
                index[1]=right;
                return index;
            }
        else if( arr[left] + arr[right] > k )
            right--;
        else
            left++;
    }
    return NULL;
}
int main()
{
    // sorted order array
    int arr[] = {1,3,4,6,7, 9,11, 14, 16};
    int n = sizeof arr/sizeof arr[0];
    int k =15;
    int *ans = pair_sum_equals_to_k(arr, n, k);
    if( ans ==  NULL )
        cout << " No such result";
    else
        cout << "index: " << ans[0] << " " << ans[1];
    return 0;
}

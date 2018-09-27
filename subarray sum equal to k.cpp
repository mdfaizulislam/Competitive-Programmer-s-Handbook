
#include <iostream>
#include <malloc.h>
using namespace std;
int* subarray_sum_equals_to_k(int *arr, int n, int k)
{
    int curr_sum=arr[0], start=0, i;

    for( i  = 1 ; i < n; i++ ){

        while( curr_sum > k && start < i-1 ){
            curr_sum-=arr[start];
            start++;
        }

        if( curr_sum == k ){
            int *index;
            index=(int *)malloc(2*sizeof(int));
            index[0]=start;
            index[1]=i-1;
            return index;
        }

        if( i < n )
            curr_sum+=arr[i];
    }

    return NULL;
}
int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23, 10, 13};
    int n = sizeof arr / sizeof arr[0];
    int k = 23;

    int *ans=subarray_sum_equals_to_k(arr,n, k);
    if( ans == NULL )
        cout << "No such result. ";
    else
        cout << "found between " << ans[0] << " and " << ans[1] ;
    return 0;
}

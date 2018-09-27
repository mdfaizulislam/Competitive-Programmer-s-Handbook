#include <iostream>
#include <malloc.h>
#include <cstring>

using namespace std;
/*
given N = 10^5
arr[i] <= 10000
K <= 1000
you have to find minimum subarray which contains all elements from 1 to k;
others elements can be included;
*/
void mini_subarr_contains_1_to_k_elements( int *arr, int n, int k)
{
    int *flag;
    flag = (int *)malloc((k+1)*sizeof(int));
    memset(flag,0,k*sizeof(int));
    int left=0, right=0, distinct_counter=0, min_diff=9999999;
    int index[2], f = 0;

    while( right < n)
    {
        if( flag[arr[right]] == 0 )
            distinct_counter++;
        if( arr[right] <= k)
            flag[arr[right]]++;
        while( distinct_counter == k )
        {
            //cout << left << " "<< right << "\n";
            if( right - left < min_diff )
            {
                min_diff = right-left;
                f = 1;
                index[0]=left;
                index[1]=right;
            }
            flag[arr[left]]--;
            if( flag[arr[left]] == 0 )
                distinct_counter--;
            left++;
        }
        right++;
    }
    if( f )
        cout << index[0] << " " << index[1] << "\n";
    else
        cout << "No such sub array\n";
}
int main()
{
    int arr[]= {4,3,1,1,2,3,6,7,4,3,2,1};
    int n = sizeof arr / sizeof arr[0];
    int k = 3;
    mini_subarr_contains_1_to_k_elements(arr,n, k);
    return 0;
}

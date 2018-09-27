#include <iostream>

using namespace std;

void minimum_subarray_sum_greaOrEq_M(int *arr, int n, int M)
{
    int left=0, right=0, cuSum=0;
    int index[2], diff=99999999;
    while(right < n )
    {
        cuSum+=arr[right];
        while( cuSum >= M )
        {
            if( right - left < diff )
            {
                diff = right-left;
                index[0]=left;
                index[1]=right;
            }
            //cout << left << " " << right << "\n";
            cuSum-=arr[left];
            left++;
        }
        right++;
    }
    cout << index[0] << " " << index[1] << "\n";
}
int main()
{
    int arr[]={4,1,2,3,0,6,7,15,2,6,3,2};
    int n= sizeof arr / sizeof arr[0];
    int M = 10;
    minimum_subarray_sum_greaOrEq_M(arr, n, M);
    return 0;
}

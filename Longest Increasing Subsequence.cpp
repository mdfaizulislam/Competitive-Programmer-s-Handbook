#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;
#define max(a,b) (a)>(b)? (a) : (b)
#define min(a,b) (a)<(b)? (a) : (b)

int _lis(int *arr, int n, int *mx_ref)
{
    if( n ==  1 )
        return 1;

    int res, max_ending_here=1;

    for( int i = 1 ; i < n ; i++ ){

        res = _lis(arr, i, mx_ref);
        if( arr[i-1] < arr[n-1] && res+1 > max_ending_here )
            max_ending_here = res+1;
     }

     if( max_ending_here > *mx_ref )
        *mx_ref = max_ending_here;

     return max_ending_here;
}
int LIS(int *arr, int Size)
{
    int mx=1;
    _lis(arr, Size, &mx);
    return mx;
}

int LIS_DP(int *arr, int n){
    // O(n^2)
    int *lis;
    lis = (int *)malloc( n * sizeof(int));

    for( int i = 0 ; i < n ; i++ )
        lis[i]=1;

    for( int i = 1 ; i < n ; i++ ){
        for( int j = 0 ; j < i ; j++ ){
            if( arr[j] < arr[i] && lis[j]+1 > lis[i] )
                lis[i] = lis[j]+1;
        }
    }

    int mx=0;
    for( int i = 0 ; i < n ; i++ )
        if( lis[i] > mx )
            mx=lis[i];
    free(lis);

    return mx;
}
int binarysearch(int *tail, int l, int r, int key)
{
    int mid;
    while( r - l > 1 ){
        mid = l + (r-l)/2;
        if( tail[mid] >= key ){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}
int LIS_NLOGN(int *arr, int Size)
{
    int *tailTable = new int[Size];
    memset(tailTable, 0, Size*sizeof(int));
    int len;

    tailTable[0] = arr[0];
    len = 1;

    for( int i = 1 ; i < Size ; i++ ){

        if( arr[i] < tailTable[0] )
            tailTable[0]=arr[i];
        else if( arr[i] > tailTable[len-1] )
            tailTable[len++] = arr[i];
        else
            tailTable[binarysearch(tailTable,-1,len-1, arr[i])] = arr[i];
    }

    delete[] tailTable;
    return len;
}
int main()
{
    //int arr[] = {6, 2, 5, 1, 7, 4, 8, 3};
    //int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80};
    //int arr[] = {10,9,2,5,3,4};
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int Size = sizeof arr/sizeof arr[0];
    cout << "LIS using recursion: " << LIS(arr, Size) << "\n";
    cout << "LIS using DP: "<< LIS_DP(arr, Size) << "\n";
    cout << "LIS nLogn: " << LIS_NLOGN(arr, Size);
    return 0;
}

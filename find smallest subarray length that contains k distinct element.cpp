/*
Motivation Problem: Given an array containing N integers, you need to find the length of the smallest contiguous
subarray that contains at least K distinct elements in it. Output "−1" if no such subarray exists.

Constraints: Number of elements in the array are around one million with each of them having value as large as 10^9 .
*/
#include <iostream>
#include <set>
#include <map>
using namespace std;
#define inf 9999999
int min(int a, int b){
    return a<b?a:b;
}
int find_length_of_distinct_k_elem_subArr(int *arr, int n, int k)
{
    int left=0, right=0, ans=inf;
    set<int> s;
    map<int, int> cnt;

    while( left < n )
    {
        while( right < n && s.size() < k )
        {
            s.insert(arr[right]);
            cnt[arr[right]]++;
            right++;
        }

        if( s.size() >= k )
        {
            ans = min(ans,right-1);
        }

        if( cnt[arr[left]] == 1 )
            s.erase(cnt[arr[left]]);

        cnt[arr[left]]--;
        left++;

    }
    if( ans == inf )
        return -1;
    else
        return ans;
}
int main()
{
    int arr[]={1,2,2,2,3,4,11,23,5,6,3,2,4,8,6,4,9};
    int n = sizeof arr /sizeof arr[0];
    int k = 4;
    int result = find_length_of_distinct_k_elem_subArr(arr, n, k);
    cout << result;
    return 0;
}

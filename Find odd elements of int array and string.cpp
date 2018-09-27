#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void find_element_of_Odd_freq()
{
    // all elements are even numbered except one. find this element
    int arr[]={1,2,3,4,1,5,5,5,2,3,4,1,2,3,4,1,2,3,4};
    int n = sizeof arr / sizeof arr[0];
    int res=0;
    for( int i = 0 ; i < n ; i++ ){

        res=res^arr[i];
    }

    cout << res;
}

void print_element_of_odd_freq_of_a_string()
{
    // given a string size 10^5, find all letters of odd frequencies
    int flag[26]={0};
    char str[]="aaaaaaabbbccdddrrrrysspppggggkkkkk";
    int n = strlen(str);
    int t;
    for( int i = 0 ; i < n ; i++ ){

        t = str[i]-'a';
        flag[t] = !(flag[t]);
    }
    for( int i = 0 ; i < 26; i++ ){

        if( flag[i] )
            printf("%c ",i+'a');
    }
}
int main()
{
    // find_element_of_Odd_freq();
    print_element_of_odd_freq_of_a_string();
    return 0;
}

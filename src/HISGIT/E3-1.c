/*Excercise 3-1 Our binary search makes two test inside the loop,
when one would suffice (at the price of more test outside). Write
a version with only one test inside the loop and measure the dif-
ference in run-time. */
#include <stdio.h>
int binarysearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high){
        mid = low + high;
        if(x != v[mid])
            (x-v[mid] > 0)? (low = mid + 1):(high = mid - 1);
        else
            return mid;
    }
    return -1;
}
int binarysearch2(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high){
        mid = low + high;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

main(){
    int v[1000];
    int x = 666*3;
    for(int i = 0; i < 1000;i++)
        v[i] = i*3;
    int s1 = binarysearch(x, v, 8);
    printf("search result:%d\n", s1);
}

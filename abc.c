#include <stdio.h>
#include <stdlib.h>

int Assending(const void *p, const void*q){
    int l = *( int*)p;
    int r = *( int*)q;
    return r-l;
}

int main(){
    
    int arr[]={5,3,4,1,2};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int elementSize = sizeof(arr[0]);
    qsort(arr,arrSize,elementSize,Assending);

    printf("Here : ");
    for(int i=0;i<arrSize;i++)
        printf("%d",arr[i]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h> 

int main() {
    int size,min,max;
    scanf("%d", &size);
    int* arr = (int*)malloc(sizeof(int) * size); //동적할당
    for(int i =0 ; i < size ; i++){
        scanf("%d",&arr[     i]);
    }
    min = arr[0];
    max = arr[0];
    for(int i =1 ; i < size ; i++){
        if( min > arr[i]){
            min = arr[i];
        }
        else if( max < arr[i]){
            max = arr[i];
        }
    }
    printf("min: %d\nmax: %d",min,max);
       
}
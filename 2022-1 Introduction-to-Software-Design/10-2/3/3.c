#include <stdio.h>

int main(){
    float arr[5];
    float *parr = arr;
    scanf("%f %f %f %f %f",parr,parr+1,parr+2,parr+3,parr+4);
    float sum = 0;
    for(int i = 0 ; i<=4 ; i++){
    *(parr+i) *= 2;
    sum += *(parr+i);
    printf("%f\n", *(parr+i) );
    }

    printf("sum: %f",sum);

    


}
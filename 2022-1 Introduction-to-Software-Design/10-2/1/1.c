#include<stdio.h>

int main(){
    int arr[5];
    scanf("%d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);

    int min = arr[0];
    int max = arr[0];
    int sum = arr[0];

    for(int i = 1 ; i<=4 ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
        else if(arr[i] > max){
            max = arr[i];
        }

        sum+=arr[i];
    }

    printf("min: %d\nmax: %d\nsum: %d",min,max,sum);
}
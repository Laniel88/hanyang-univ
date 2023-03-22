#include <stdio.h>

int main(){

    int arr[3][2];
    scanf("%d %d %d %d %d %d",&arr[0][0],&arr[0][1],&arr[1][0],&arr[1][1],&arr[2][0],&arr[2][1]);
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
#include<stdio.h>

int main(){
    int num1, num2, num3, min, max;
    scanf("%d %d %d",&num1,&num2,&num3);
    min = num1;
    max = num1;
    //min 찾기
    if(min > num2)
        min = num2;
    if(min > num3)
        min = num3;
    //max 찾기
    if(max < num2)
        max = num2;
    if(max < num3)
        max = num3;

    printf("min : %d\nmax: %d",min,max);
    return 0;
}
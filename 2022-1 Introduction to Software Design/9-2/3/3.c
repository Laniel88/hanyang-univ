#include <stdio.h>

int sumTotal(n){
    if(n == 1)
        return 1;
    else
        return n+sumTotal(n-1);
}

int main(){
    int num;
    scanf("%d",&num);
    printf("%d",sumTotal(num));
    return 0;
}
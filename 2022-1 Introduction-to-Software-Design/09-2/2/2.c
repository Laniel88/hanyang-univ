#include <stdio.h>

int gMul = 1;

int addTotal(n){
    int sum;
    sum = 0;
    for(int i=1;i<=n;i++){
        sum += i;
    }
    return sum;
}

int mulTotal(n){
    int mul;
    mul = 1;
    for(int i=1;i<=n;i++){
        mul *= i;
    }
    gMul = mul;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("addTotal(): %d\n",addTotal(n));
    mulTotal(n);
    printf("gMul: %d\n",gMul);

    return 0;
}
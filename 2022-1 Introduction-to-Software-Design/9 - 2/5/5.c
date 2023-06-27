#include <stdio.h>

int Fibo(n){
    if(n == 0){
        return 0;
    } 
    else if(n == 1){
        return 1;
    }
    else{
        return Fibo(n-1)+Fibo(n-2);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",Fibo(n));
    return 0;
}
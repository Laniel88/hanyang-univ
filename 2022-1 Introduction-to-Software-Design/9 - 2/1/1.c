#include <stdio.h>

int add(a,b){
    return  a + b ;
}

int sub(a,b){
    return a-b;
}

int mul(a,b){
    return a*b;
}

double div(a,b){
    return (float)a/(float)b;
}

int mod(a,b){
    return a%b;
}

void printMsg(){
    printf("completed");
}

int main(){

    int a, b; 
    scanf("%d\n%d",&a,&b);
    printf("sum: %d\n",add(a,b));
    printf("difference: %d\n",sub(a,b));
    printf("product: %d\n",mul(a,b));
    printf("divison: %.10f\n",div(a,b));
    printf("remainder: %d\n",mod(a,b));
    printMsg();

    return 0;
}
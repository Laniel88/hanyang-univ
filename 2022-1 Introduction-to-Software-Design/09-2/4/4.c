#include<stdio.h>

void printline(n){
    for(int i =1 ; i<= n ; i++){
        printf("%d ",i);
    }
    printf("\n");
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i =1 ; i<= n ; i++){
        printline(i);
    }
    for(int i = n ; i>=1 ; i--){
        printline(i);
    }
}
#include<stdio.h>

int combi(n,r){
    if(r == 1){
        return n;
    }
    else if(n == r){
        return 1;
    }
    else{
        return combi(n-1,r-1)+combi(n-1,r);
    }
}


int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%d",combi(n,r));
}
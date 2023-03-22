#include <stdio.h>

int main(){
    int cnt;
    int i =1;
    scanf("%d", &cnt);
    while(i<10){
        printf("%d*%d=%d\n",cnt,i,cnt*i);
        i++;
    }
    
}
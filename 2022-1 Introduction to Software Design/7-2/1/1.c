#include <stdio.h>

int main(){
    int cnt;
    scanf("%d", &cnt);
    for(int i=1 ; i < 10 ; i++){
        printf("%d*%d=%d\n",cnt,i,cnt*i);
    }
    
}
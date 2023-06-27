#include <stdio.h>

int main(){
    int arr[5];
    int *ar = arr;
    int ch;
    scanf("%d %d %d %d %d",ar,ar+1,ar+2,ar+3,ar+4);
    
    ch = *(ar);
    *(ar) = *(ar+4);
    *(ar+4) = ch;

    ch = *(ar+1);
    *(ar+1) = *(ar+3);
    *(ar+3) = ch;

    printf("%d %d %d %d %d",*(ar),*(ar+1),*(ar+2),*(ar+3),*(ar+4));

}
#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    if (num < -10)
        printf("n < -10");
    else if (num < 0 && num >= -10)
        printf("-10 <= n < 0");
    else if (num >= 0 && num <10)
        printf("0 <= n <10 ");
    else
        printf("n >=10");

    return 0;

}
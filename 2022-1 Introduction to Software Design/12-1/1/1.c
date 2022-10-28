#include <stdio.h>

void square(double *point ){

    double temp = *point;
    *point = temp*temp;
}

int main(){
    double dvar;
    scanf("%lf", &dvar);
    square(&dvar);
    printf("%f",dvar);
    return 0;
}
#include<stdio.h>

int main(){
    double num1 = 1.23456789;
    double num2 = 0.0000123456789;
    printf("1) %0.10f %0.10f\n",num1,num2);
    printf("2) %e %e\n",num1,num2);
    printf("3) %E %E\n",num1,num2);
    printf("4) %g %g\n",num1,num2);
    printf("5) %G %G\n",num1,num2);
}
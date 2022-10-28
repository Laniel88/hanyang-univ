#include <stdio.h>

int main(){
    int i;
    double d;
    char c;

    scanf("%d %lf %c",&i,&d,&c);
    printf("i: %d, %p\nd: %lf, %p\nc: %c, %p\n",i,&i,d,&d,c,&c);
    int *pi = &i;
    double *pd = &d;
    char *pc = &c;
    *pi+=1;
    *pd+=1;
    *pc+=1;
    printf("i+1: %d\nd+1: %lf\nc+1: %c\n",i,d,c);
    printf("size of pi: %d\nsize of pd: %d\nsize of pc: %d\n",(int)sizeof(pi),(int)sizeof(pd),(int)sizeof(pc));
}
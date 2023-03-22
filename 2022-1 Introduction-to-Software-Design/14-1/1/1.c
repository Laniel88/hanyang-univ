#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int xpos;
    int ypos;
} Point;

int main(){
    Point* pp1 = (Point*)malloc(sizeof(Point));
    scanf("%d %d",&pp1->xpos,&pp1->ypos);
    printf("%d %d\n", pp1->xpos,pp1->ypos);
    free(pp1);
    return 0;
}
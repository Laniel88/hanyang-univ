#include <stdio.h>

typedef struct {
    int xpos;
    int ypos;
} Point;

Point getScale2xPoint(Point p){
    Point p_2x;
    p_2x.xpos = p.xpos * 2;
    p_2x.ypos = p.ypos * 2;
    return p_2x;
}

int main(){
Point p1;
scanf("%d %d",&p1.xpos,&p1.ypos);
Point p2 = getScale2xPoint(p1);
printf("%d %d\n", p2.xpos, p2.ypos);
return 0;
}
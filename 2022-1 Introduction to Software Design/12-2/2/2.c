#include <stdio.h>

typedef struct {
    char name[7];
    int score;
} Person;

void printScoreStars(Person* persons, int len){
    int cnt;
    for(int i = 0 ; i < len ; i++){
        printf("%-7s",persons[i].name);
        cnt = persons[i].score/5;
        for(int j = 0 ; j < cnt; j++ ){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    Person p[3];
    for(int i = 0 ; i < 3 ; i++){
        scanf("%s %d",p[i].name,&p[i].score);
    }
    printScoreStars(p,3);
    return 0;
}

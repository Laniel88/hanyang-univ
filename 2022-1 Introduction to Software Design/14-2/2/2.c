#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int score;
} Person;

void printScoreStars(Person* persons, int len){
    int cnt;
    for(int i = 0 ; i < len ; i++){
        printf("%-10s",persons[i].name);
        cnt = persons[i].score/5;
        for(int j = 0 ; j < cnt; j++ ){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int temp_score,cnt;
    char temp_name[10];
    Person *personArr=(Person *) malloc(sizeof(Person));     
    Person *temp_personArr;

    for(cnt=0; ;cnt++){
        scanf("%s %d",temp_name,&temp_score);
        if(strcmp(temp_name,"END") == 0 && temp_score == 0){ break; }
        else{
            //set tmep_personArr
            temp_personArr = (Person *) malloc(sizeof(Person) * (cnt+1));

            //copy temp_personArr
            for(int i = 0 ; i < cnt ; i++){
                strcpy(temp_personArr[i].name,personArr[i].name);
                temp_personArr[i].score = personArr[i].score;
            }
            free(personArr);
            //set new personArr
            personArr = (Person *) malloc(sizeof(Person) * (cnt+1));
            for(int i = 0 ; i < cnt ; i++){
                strcpy(personArr[i].name,temp_personArr[i].name);
                personArr[i].score = temp_personArr[i].score;
            }
            free(temp_personArr);                   //push new value
            strcpy(personArr[cnt].name,temp_name);  //push new value
            personArr[cnt].score = temp_score;
        }
    }
    printScoreStars(personArr,cnt);

    free(personArr);
    return 0;
}
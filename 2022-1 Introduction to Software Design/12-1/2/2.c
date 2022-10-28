#include <stdio.h>

struct Person {    
    char name[10];        
    int age;
} per1;

int main(){
    scanf("%s %d",per1.name,&per1.age);
    printf("name: %s\nage: %d",per1.name,per1.age);    
    return 0;
}
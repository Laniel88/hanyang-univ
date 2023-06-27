#include <stdio.h>
#include <string.h>


int main(){
    char str1[10];
    char str2[10];

    scanf("%s %s",str1,str2);

    int ck = strcmp(str1,str2); 
    printf("str1: %s\nstr2: %s\n",str1,str2);
    printf("length of str1: %d\nlength of str2: %d\n",(int)strlen(str1),(int)strlen(str2));
    strcat(str1,str2);
    printf("str1+str2: %s\n",str1);
    if(ck == 0){
        printf("same");
    }
    else{
        printf("not same");
    }
    
}
#include<stdio.h>
#include<ctype.h>
#include <string.h>

int main(){
    char str[10];
    scanf("%s",str);
    for(int i =0 ; i < (int)strlen(str) ; i++){
        if((int)str[i]>64 && (int)str[i]<91){
            str[i] = tolower(str[i]);
        }
        else{
            str[i] = toupper(str[i]);
        }
    }

    printf("%s",str);

}
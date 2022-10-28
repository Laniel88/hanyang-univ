#include <stdio.h>

void printString(const char* str){
    printf("%s\n",str);
}

int main(){

    void (*printfStr) (const char*);
    printfStr = printString;
    char* strArr[3] = {"One", "Two" , "Three"};
    for(int i = 0 ; i < 3 ; i++){
        printfStr(strArr[i]);
    }
    return 0;

}
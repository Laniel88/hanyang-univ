#include <stdio.h>

void swap(char** str1, char** str2);
void printArray(char* str1, char* str2);

int main(){

    char* Arr[2] = {"aaa", "bbb"};
    printArray(Arr[0],Arr[1]);
    swap(&Arr[0],&Arr[1]);
    printArray(Arr[0],Arr[1]);

}

void swap(char** str1, char** str2){
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void printArray(char* str1, char* str2){
    printf("Array [0]:%s, [1]:%s,\n",str1,str2);
}

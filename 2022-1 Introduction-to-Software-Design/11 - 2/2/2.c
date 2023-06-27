#include <stdio.h>
#include <string.h>

int main() {
    char arr[10];
    scanf("%s", arr);
    int k = strlen(arr);
    int F =0;
    if(k%2==0){
        for(int i=0; i<=(k-1)/2; i++){
            if(arr[i]+32 != arr[k-1-i] || arr[i]-32 != arr[k-1-i]){
            continue;
            }
            else if(arr[i] != arr[k-1-i]){
            F++;
            }
        }
        if(F>=1){
        printf("This is not a palindrome");
        }
        else{    
        printf("This is a palindrome");
        }
    }
    else{
        for(int i=0; i<(k-1)/2; i++){
            if(arr[i]+32 != arr[k-1-i] || arr[i]-32 != arr[k-1-i]){
            continue;
            }
            else if(arr[i] != arr[k-1-i]){
            F++;
            }
        }
        if(F>=1){
        printf("This is not a palindrome");
        }
        else{ 
        printf("This is a palindrome");
        }
    }  
    return 0;
}
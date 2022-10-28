#include <stdio.h>
#include <string.h>

int main() {
    char arr[10];
    int check[10];
    scanf("%s", arr);
    for (int i = 0; i < 10; i++) {
        check[i] = 1;
    }
    for (int i = 0; i < strlen(arr); i++) {
        int count = 1;
        for (int j = i+1; j < strlen(arr); j++) {
            if (arr[i] == arr[j]) {
            count += 1;
            check[j] = 0;
            }
        }
        if (check[i] != 0){
            printf("'%c': %d\n", arr[i], count);
        }
    }

}
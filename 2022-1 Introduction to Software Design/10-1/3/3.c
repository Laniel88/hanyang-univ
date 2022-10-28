    #include <stdio.h>

    int main(){
        char ch[10];
        int leng = 0;
        scanf("%s",ch);
        for(int i = 0 ; ch[i] != '\0' ; i++){
            leng++;
        }
        printf("%d",leng);
    }
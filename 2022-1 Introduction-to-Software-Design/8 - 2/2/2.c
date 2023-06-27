#include<stdio.h>

int main(){
    char chr;
    int asci;
    while(1){
        scanf(" %c",&chr);
        asci = (int)chr;

        if(asci >=97 && asci <=122){
            printf("-> %c\n",asci-32);
        }
        else if(asci >=65 && asci <= 90){
            printf("-> %c\n",asci+32);
        }
        else if(asci >= 49 && asci <= 57){
            printf("-> %c\n",asci);
        }
        else{
            printf("exit\n");
            break;
        }
        
    }

    return 0;
}
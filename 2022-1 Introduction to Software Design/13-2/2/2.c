#include <stdio.h>
#include <string.h>

#define NON_EXIST 0
#define YES_EXIST 1
#define EXIT_CODE -1

void getWord(char* word,char wordList[10][20],int cnt);
int searchWord(char wordList[10][20], int cnt);

int main(){
    int cnt = 10, chk = 1;
    char wordList[10][20];

    for(int i = 0; i < 10 ; i++){
        getWord(wordList[i],wordList,i);
        if(strcmp(wordList[i],"end")==0){
            cnt = i;
            break;
        }
    }

    printf("%d words in the list :\n",cnt);
    for(int i = 0 ; i < cnt ; i++){
        printf("%s ",wordList[i]);
    }
    printf("\n");


    while(chk){
        switch(searchWord(wordList,cnt)){
        case YES_EXIST:
            printf("This word is in the list.\n");
            break;
        case NON_EXIST:
            printf("This word is NOT in the list.\n");
            break;
        case EXIT_CODE:
            chk = 0;
            break;
        }
    }
    
    return 0;
}

void getWord(char* word,char wordList[10][20],int cnt){
    char temp[20];
    int check = NON_EXIST;
    printf("Enter a word (Enter 'end' to quit) : ");
    scanf("%s",temp);
    if(strcmp(temp,"end") == 0){
        strcpy(word,temp);
    }
    else{
        for(int i = 0; i < cnt ; i++){
            if(strcmp(temp,wordList[i]) == 0){
                printf("This word already exists. Please enter another word.\n");
                getWord(word,wordList,cnt);
                check = YES_EXIST;
            }
        }
        if(check == NON_EXIST){
        strcpy(word,temp);
        }
    }
}

int searchWord(char wordList[10][20], int cnt){
    char temp[20];
    int check = NON_EXIST;
    printf("Enter a word to search (Enter 'end' to quit) : ");
    scanf("%s",temp);
    if(strcmp(temp,"end") == 0){
        return EXIT_CODE;
    }
    else{
        for(int i = 0; i < cnt ; i++){
            if(strcmp(temp,wordList[i]) == 0)
                return YES_EXIST;
        }
        return NON_EXIST;
    }
}
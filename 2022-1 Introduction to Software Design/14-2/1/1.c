#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NON_EXIST 0
#define YES_EXIST 1
#define EXIT_CODE -1

void getWord(char* word,char **wordList,int cnt);
int searchWord(char** wordList, int cnt);

int main(){
    int cnt = 0, chk = 1;
    char temp[20];
    char** wordList=(char**)malloc(sizeof(char*));
    char** temp_wordList=(char**)malloc(sizeof(char*));
    
    while(1){
        getWord(temp,wordList,cnt);
        if(strcmp(temp,"end")==0){
            break;
        }
        else{
            //set temp_wordlist
            temp_wordList = (char**) malloc(sizeof(char*)*(cnt+1));
            for(int i = 0; i< cnt+1 ; i++){
                temp_wordList[i] = (char*)malloc(sizeof(char)*20);
            }

            //copy value to temp_wordlist
            for(int i = 0; i< cnt; i++){
                strcpy(temp_wordList[i],wordList[i]);
            }
            strcpy(temp_wordList[cnt],temp);
            free(wordList);
            
            //set wordList(new)
            wordList = (char**) malloc(sizeof(char*)*(cnt+1));
            for(int i = 0; i< cnt+1 ; i++){
                wordList[i] = (char*)malloc(sizeof(char)*20);
            }

            //copy value to wordList(new) from temp_wordlist
            for(int i = 0; i< cnt+1; i++){
                strcpy(wordList[i],temp_wordList[i]);
            }
            free(temp_wordList);
            cnt++;
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
    free(wordList);
    return 0;
    
}


int searchWord(char** wordList, int cnt){
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

void getWord(char* word,char **wordList,int cnt){
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


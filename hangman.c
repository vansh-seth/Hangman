#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WORDS 10
#define WORDLEN 40
#define CHANCE 6
void printBody(int mistakes, char* body)
{
    printf("\tMistakes :%d\n", mistakes);
    switch(mistakes)
    {
        case 6:
            body[6] = '\\';
            break;
        case 5:
            body[5] = '/';
            break;
        case 4:
            body[4] = '\\';
            break;
        case 3:
            body[3] = '|';
            break;
        case 2:
            body[2] = '/';
            break;
        case 1:
            body[1] = ')', body[0] = '(';
            break;
        default:
            break;
    }
    printf("\t _________\n"
      "\t|         |\n"
      "\t|        %c %c\n"
      "\t|        %c%c%c\n"
      "\t|        %c %c\n"
      "\t|             \n"
      "\t|             ", body[0], body[1], body[2],
      body[3], body[4], body[5], body[6]);
}

void printWord(char* guess, int len)
{
    printf("\t");
    for (int i = 0; i < len; ++i)
    {
            printf("%c ", guess[i]);
    }
    printf("\n\n");
}

int main()
{
    int n=0;
    while(n!=1)
    {


    printf("\n\t  Hang man !!!!.");
    printf("\n\n\t Rules : ");
    printf("\n\t - Maximum 6 mistakes are allowed.");
    printf("\n\t - All alphabet should in lower case.");
    char *body = malloc(CHANCE+1);
    char word[10];
    char ch;
    int l;
    printf("\n\t\t\n Enter the word you wanna give the opponent: ");
    while((ch=_getch())!=' ')
    {
        word[l] = ch;
        l++;
        printf("*");
    }
    word[l] = '\0';
    int len = strlen(word);
    char *guessed = malloc(len);
    char falseWord[CHANCE];
    memset(body, ' ', CHANCE+1);
    memset(guessed, '_', len);
    char guess;
    bool found;
    char* win;
    int mistakes = 0;
    do
    {
        found = false;
        printf("\n\n");
        printBody(mistakes, body);
        printf("\n\n");
        printf("\tFalse Letters : ");
        if(mistakes == 0)
        {
                printf("None\n");
        }
        for (int i = 0; i < mistakes; ++i)
        {
            printf("%c", falseWord[i]);
        }
        printf("\n\n");
        printWord(guessed, len);
        printf("\tGive me a alphabet in lower case : ");
        do
        {
            scanf("%c",&guess);
        } while ( getchar() != '\n' );
        for (int i = 0; i < len; ++i)
        {
            if(word[i] == guess)
            {
                found = true;
                guessed[i] = guess;
            }
        }
        if(!found)
        {
            falseWord[mistakes] = guess;
            mistakes += 1;
        }
        win = strchr(guessed, '_');
        }while(mistakes < CHANCE && win != NULL);
        if(win == NULL)
        {
            printf("\n");
            printWord(guessed, len);
            printf("\n\t You have won!!! \n\t word guessed : %s\n\n", word);
        }
        else
        {
            printf("\n");
        printBody(mistakes, body);
        printf("\n\n\tBetter try next time. \n\t Word was %s\n\n", word);
        }
        free(body);
        free(guessed);
        printf("\tWanna Exit??\n");
        printf("\tPress 1\n");
        scanf("%d",&n);
    }
}

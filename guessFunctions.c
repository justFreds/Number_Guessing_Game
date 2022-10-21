//FUNCTIONS
//CREATE gameFunctions.c
//  defaultGame()
//  customGame()
//  exit()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "guessFunctions.h"

//SENTINAL CHECK COMPARSION
#define SENT_CHECK(y) strcmp(y, "q") == 0 || strcmp(y, "Q") == 1
//GUESS PRINT AND FLUSH
#define GUESS(x) printf("Enter your guess: ");fflush(stdin);scanf("%s", x); 

//DEFAULT GAME NUMBER FROM 1-10
void defaultGame(void)
{
    printf("\n----Default Game Mode----\n");
    //declarations
    int count = 0, secretNumber, userGuess;
    char exitTracker, sentinal[20];
    
    srand(time(NULL));
    secretNumber = rand()%10+1;     //RANDOM NUMBER FROM 1-10

    printf("A number between 1-10 has been generated.\n");
    printf("Press Q/q at any time to return to previous menu.\n");
    
    GUESS(sentinal);
    if(SENT_CHECK(sentinal))        //RETURNS TO MENU
        goto skip;
    userGuess = atoi(sentinal);    
    
    //MAIN LOOP
    while(userGuess != secretNumber) {

        while (userGuess <= 0 || userGuess > 10) {       //CHECK BOUNDS
            printf("ERROR!\nNumber Out Of Bounds!\n");
            GUESS(sentinal);
            userGuess = atoi(sentinal);
            if(SENT_CHECK(sentinal))
                goto skip;
        }                
        if(userGuess < secretNumber) {                  //HINTS
            printf("Guess is low. Try again.\n");
            printf("Enter your guess: ");
        }
        else {
            printf("Guess is high. Try again.\n");
            printf("Enter your guess: ");
        }
        GUESS(sentinal);                                //REPEAT
        if(SENT_CHECK(sentinal))
            goto skip;
        userGuess = atoi(sentinal);
    }

    if(userGuess == secretNumber) {                     
        printf("\n\nCongrats! You guessed %d correctly!\nReturning to Main Menu now!\n", userGuess);
        fflush(stdin);
    }
    else {
        skip:
        printf("\n\nThe random number was: %d\nReturning to Main Menu now!\n", secretNumber);
        fflush(stdin);
    }
}

void customGame(void) {

}

void exitGame(void) {
    printf("\nGoodbye User!\n");
    exit(EXIT_SUCCESS);
}
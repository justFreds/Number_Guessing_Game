#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "guessFunctions.h"
//SAVE THE LAST MAX NUMBER INTO A FILE
//CREATE A MODE CALLED LOAD GAME
//READ THAT NUMBER & WRITE INTO customMax

//SENTINAL CHECK COMPARSION
#define SENT_CHECK(y) strcmp(y, "q") == 0 || strcmp(y, "Q") == 1
//GUESS PRINT AND FLUSH
#define GUESS(x) printf("\nEnter your guess: ");fflush(stdin);scanf("%s", x); 

//  defaultGame()
//DEFAULT GAME NUMBER FROM 1-10
void defaultGame(void) {

    printf("\n----Default Game Mode----\n");
    //declarations
    const int DEFAULTMAX = 10;
    int secretNumber, userGuess;
    char sentinal[20];
    
    srand(time(NULL));
    secretNumber = rand()%DEFAULTMAX+1;     //RANDOM NUMBER FROM 1-10

    printf("A number between 1-%d has been generated.\n", DEFAULTMAX);
    printf("Press Q/q at any time to return to previous menu.");
    
    GUESS(sentinal);
    if(SENT_CHECK(sentinal))        //RETURNS TO MENU
        goto skip;
    userGuess = atoi(sentinal);    
    
    //MAIN LOOP
    while(userGuess != secretNumber) {

        while (userGuess <= 0 || userGuess > DEFAULTMAX) {       //CHECK BOUNDS
            printf("\nERROR!\nNumber Out Of Bounds!\n");
            GUESS(sentinal);
            userGuess = atoi(sentinal);
            if(SENT_CHECK(sentinal))
                goto skip;          //RETURNS TO MENU
        }                
        if(userGuess < secretNumber) {                  //HINTS
            printf("Guess is low. Try again.");
        }
        else {
            printf("Guess is high. Try again.");
        }
        GUESS(sentinal);                                //REPEAT
        if(SENT_CHECK(sentinal))
            goto skip;              //RETURNS TO MENU
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
//  customGame()
void customGame(void) {

    printf("\n----Custom Game Mode----\n");
    //declarations
    int secretNumber, userGuess, customMax;
    char sentinal[20];

    //GET customMax from user
    printf("Enter The Custom Max Number To Guess (1-%d): ", RAND_MAX);
    fflush(stdin);
    scanf("%d", &customMax);
    while(customMax > RAND_MAX || customMax <= 0) {             //CHECK BOUNDS
        printf("\nERROR!\nNumber Out Of Bounds!\n");
        printf("Enter The Custom Max Number To Guess (1-%d): ", RAND_MAX);
        fflush(stdin);
        scanf("%d", &customMax);
    }

    //Write customMax into a file using w+
    FILE *filePtr;
    filePtr = fopen("saveFile.txt", "w+");      //OPENS in w+ mode
    fprintf(filePtr, "%d", customMax);
    fclose(filePtr);


    srand(time(NULL));
    secretNumber = rand()%customMax+1;     //RANDOM NUMBER FROM 1-customMax

    printf("A number between 1-%d has been generated.\n", customMax);
    printf("Press Q/q at any time to return to previous menu.");
    
    GUESS(sentinal);
    if(SENT_CHECK(sentinal))        //RETURNS TO MENU
        goto skip;
    userGuess = atoi(sentinal);    
    
    //MAIN LOOP
    while(userGuess != secretNumber) {

        while (userGuess <= 0 || userGuess > customMax) {       //CHECK BOUNDS
            printf("\nERROR!\nNumber Out Of Bounds!\n");
            GUESS(sentinal);
            userGuess = atoi(sentinal);
            if(SENT_CHECK(sentinal))
                goto skip;          //RETURNS TO MENU
        }                
        if(userGuess < secretNumber) {                  //HINTS
            printf("Guess is low. Try again.");
        }
        else {
            printf("Guess is high. Try again.");
        }
        GUESS(sentinal);                                //REPEAT
        if(SENT_CHECK(sentinal))
            goto skip;              //RETURNS TO MENU
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
void loadGame(void) {
    
    printf("\n----Save File Loaded----\n");
    //declarations
    int secretNumber, userGuess, customMax;
    char sentinal[20];
    FILE *filePtr;

    filePtr = fopen("saveFile.txt", "r");        //READ MODE
    fscanf(filePtr, "%d\n", &customMax);    
    fclose(filePtr);

    printf("Custom Max: %d\n", customMax);

    srand(time(NULL));
    secretNumber = rand()%customMax+1;     //RANDOM NUMBER FROM 1-customMax

    printf("A number between 1-%d has been generated.\n", customMax);
    printf("Press Q/q at any time to return to previous menu.");
    
    GUESS(sentinal);
    if(SENT_CHECK(sentinal))        //RETURNS TO MENU
        goto skip;
    userGuess = atoi(sentinal);    
    
    //MAIN LOOP
    while(userGuess != secretNumber) {

        while (userGuess <= 0 || userGuess > customMax) {       //CHECK BOUNDS
            printf("\nERROR!\nNumber Out Of Bounds!\n");
            GUESS(sentinal);
            userGuess = atoi(sentinal);
            if(SENT_CHECK(sentinal))
                goto skip;          //RETURNS TO MENU
        }                
        if(userGuess < secretNumber) {                  //HINTS
            printf("Guess is low. Try again.");
        }
        else {
            printf("Guess is high. Try again.");
        }
        GUESS(sentinal);                                //REPEAT
        if(SENT_CHECK(sentinal))
            goto skip;              //RETURNS TO MENU
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
//  exit()
void exitGame(void) {
    printf("\nThanks For Playing\nGoodbye User!\n");
    exit(EXIT_SUCCESS);
}
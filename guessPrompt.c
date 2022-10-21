#include <stdio.h>  //getchar() - https://en.cppreference.com/w/c/io/getchar 
#include <stdlib.h>
//PROMPT: INTERACTIVE MENU
//                          Press 1 To Play Game
//                          Press 2 To Change Max Number
//                          Press 3 To Quit

//maybe like in promptMenu.c example from class?
//  CREATE A PROMPT MENU LIKE FILE
//  promptGame.c
//int getLine()
//void menuDisplay()
//int menuChoice()
        //1: goes to the function with guessing game between (1-10)
        //2: goes to the function with guessing game between (1-UserDefinedMax)
        //3: Exits
//void menuProcess()


#define MAXLEN 50

int getLine(char* buff, int buffLength) {
    int c, i = 0;
    while((c = getchar()) != '\n' && c != EOF) {
        if(i < buffLength) {
            buff[i++] = c;
        }
        buff[i] = '\0';

        return(c == EOF) ? -1 : i;
    }
}
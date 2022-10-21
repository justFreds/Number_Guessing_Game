//PROMPT: INTERACTIVE MENU
//                          Press 1 To Play Game
//                          Press 2 To Change Max Number
//                          Press 3 To Quit
#include <stdio.h>  //getchar() - https://en.cppreference.com/w/c/io/getchar 
#include <stdlib.h>
#define MAXLEN 50

//int getLine()
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
//void menuDisplay()
static void menuDisplay(int n, const char *const items[]) 
{ 
    printf("\nWelcome User!\n"); 

    for (int i = 1; i <= n; i++) 
        printf("\t%i) %s\n", i, items[i-1]); 

    printf("Or Type Q/q To Quit At Any Time: "); 
} 
//int menuChoice()
        //1: goes to the function with guessing game between (1-10)
        //2: goes to the function with guessing game between (1-UserDefinedMax)
        //3: Exits
static int menuChoice(int n, const char *const items[]) 
{ 
    int num;
    char quit; 
    char line[MAXLEN + 1]; 
    menuDisplay(n, items); 

    while (getLine(line, MAXLEN) != -1) 
    {
        if(sscanf(line, "%c", quit) == 'q' || sscanf(line, "%c", quit) == 'Q') {
            goto skip;
        }
        if(sscanf(line, "%i", &num) ==1 && 0 <= num && num <= n) 
            return num; 
        else 
            printf("Enter a value between 1 and %i: ", n); 
    }
    skip: 
    return EXIT_SUCCESS; 
}
void menuProcess(int numMenuChoices, const char *const menuItems[], void (*fPtrs[])(void)) 
{ 
    int choice; 
    while ((choice = menuChoice(numMenuChoices, menuItems)) != 0) 
        fPtrs[choice -1](); //call to function 
}  
//void menuProcess()

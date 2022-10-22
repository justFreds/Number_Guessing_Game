/* git reminders
git remote add origin https://github.com/justFreds/Number_Guessing_Game.git
git branch -M main
git push -u origin main
*/

//****DYNAMIC LINKING TO MAYBE SAVE A BRANCH WITH CUSTOM MAX VALUE??*****
//PROMPT: INTERACTIVE MENU
//                          Press 1 To Play Game
//                          Press 2 To Change Max Number
//                          Press 3 To Quit

#include <stdio.h> 
#include <stdlib.h> 
#include "guessFunctions.h"

//constant array of const strings
const char * const menuSelection[] = {"Play Default Game", "Play Custom Game", "Load Save File", "Quit"};
//array of Ptrs, pointing to functions - This is a complex data type 
void (*menuFuncPtrs[])(void) = {defaultGame, customGame, loadGame, exitGame};

int main() {
        //prototype from guessPrompt.c
        void menuProcess(int, const char *const[], void(*[])(void));
        
        //determine size of menu
        const int choices = sizeof(menuFuncPtrs)/sizeof(menuFuncPtrs[0]);

        menuProcess(choices, menuSelection, menuFuncPtrs);

        return EXIT_SUCCESS;
}
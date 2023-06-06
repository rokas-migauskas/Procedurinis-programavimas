//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//
#include <stdio.h>
#include "VartotojoSasajosFunkcijos.h"


// shows menu and returns number of choice
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    //Printing title
    printf("%s\n",menuTitle);

    //Printing options
    for(int i=1; i<=menuSize; ++i){
        printf("%d. %s\n", i, menuOptions[i-1]);
    }

    //Printing message encouraging input
    printf("%s\n", inputMsg);

    //Basic validation
    int input;
    if(scanf("%d", &input)!=1 || (input>menuSize || input<1)){
        printf("Wrong input!\n");
        if(getchar()!='\n') {
            scanf("%*[^\n]");
        }
        //If validation did not pass, call the function again and repeat the process
        showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    }
    //If validation passed, return choice number
    else return input;
}


// validates if input is integer and whether it falls into the given bounds, returns said input.
int intValidation(int lowerBound, int upperBound){
    int result;
    while(scanf("%d", &result)!=1 || getchar()!='\n' || result>upperBound || result<lowerBound){
        printf("Wrong input!\n");
        printf("Please try again.\n");
        scanf("%*[^\n]");
    }
    return result;
}
#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main() {
    char *menuOptions[3]={{"Testi"},{"Iseiti"},{"Idk daryk ka nori"}};
    int x= showMenu("Title", menuOptions, 3, "Prasome ivesti pasirinkima:\n");
    printf("Pasirinkimas:\n%d. %s\n", x, menuOptions[x-1]);
    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    printf("%s\n",menuTitle);
    for(int i=1; i<=menuSize; ++i){
        printf("%d. %s\n", i, menuOptions[i-1]);
    }
    printf("%s\n", inputMsg);
    int input;
    if(scanf("%d", &input)!=1 || getchar()!='\n' || (input>menuSize || input<1)){
        scanf("%*[^\n]");
        showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    }
    else return input;
}
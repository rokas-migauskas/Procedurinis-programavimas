//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//
#include "StrukturosFunkcijos.h"
#include "VartotojoSasajosFunkcijos.h"

int main(){
    Node *head;
    initializeList(&head);

    char *menuOptions[6] = {{"Leave"},
                            {"Push student to list"},
                            {"Display entire list"},
                            {"Pick a student from list to display"},
                            {"Delete student from list"}};
    while(1) {
        int choice = showMenu("Choose a function:", menuOptions, 5, "Please make your choice:");
        printf("Choice:\n%d. %s\n", choice, menuOptions[choice - 1]);
        if (choice == 1){
            break;
        }
        if (choice == 2) {
            pushStudent(&head, inputStudent());
        }
        if (choice == 3) {
            printList(head, printStudent);
        }
        if (choice == 4){
            int size= getCurrSize(head);
            printf("Choose which student number to display:\n");
            int index= intValidation(1, size);
            printStudent(getNth(head, index-1));
        }
        if (choice == 5){
            deleteStudent(&head, inputStudent());
        }
    }
    printf("\nLeft successfully\n");
    return 0;
}

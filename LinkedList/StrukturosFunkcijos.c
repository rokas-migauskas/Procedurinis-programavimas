//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//

#include "StrukturosFunkcijos.h"


/*Function that prints list
IMPORTANT: There must be another subfunction (ex: printStudent below)
that prints corresponding data type to type passed*/
void printList(struct Node *node, void (*ptr)(void *)){
    if (node==NULL){
        printf("No nodes exist in list.\n");
        return;
    }
    int count=1;
    while (node != NULL) {
        printf("%d.\n", count);
        (*ptr)(node->data);
        node = node->next;
        ++count;
    }

    printf("\n");
}

/*function that specifically prints the Student structure declared in the header file
StrukturosFunkcijos.h*/
void printStudent(void *x){
    Student *temp= x;
    printf("First name: %s\n", (char *)temp->firstName);
    printf("Last name: %s\n", (char *)temp->lastName);
    printf("Course number: %d\n\n", temp->courseNo);
}


/*function that takes user input and returns a Student struct variable.
Also includes basic validation*/
Student inputStudent(){
    Student temp;
    printf("Input first name:\n");
    while(scanf("%s", temp.firstName)!=1 || getchar()!='\n'){
        printf("Error, bad input!\n");
        printf("Please try again.\n\n");
        printf("Input first name:\n");
    }

    printf("Input last name:\n");
    while(scanf("%s", temp.lastName)!=1 || getchar()!='\n'){
        printf("Error, bad input!\n");
        printf("Please try again.\n\n");
        printf("Input last name:\n");
    }
    printf("Input course number:\n");
    while(scanf("%d", &temp.courseNo)!=1 || getchar()!='\n'){
        printf("Error, bad input!\n");
        printf("Please try again.\n\n");
        printf("Input course number:\n");
    }
    printf("Input successful.\n");

    return temp;
}

/*Uses push command from VienpusioSarasoFunkcijos.h to specifically push a
Student variable declared in StrukturosFunkcijos.h*/
void pushStudent(Node **head, Student x){
    void *temp = &x;
    push(head, temp, sizeof(Student));
}


/*Uses deleteNodeGivenKey command from VienpusioSarasoFunkcijos.h to specifically delete a
Student variable declared in StrukturosFunkcijos.h by being given a key*/
void deleteStudent(Node **head, Student x){
    void *temp = &x;
    deleteNodeGivenKey(head, temp, sizeof(Student));
}

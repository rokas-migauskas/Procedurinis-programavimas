//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//

#include "VienpusioSarasoFunkcijos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef VARTOTOJOSASAJA_C_STRUKTUROSFUNKCIJOS_H
#define VARTOTOJOSASAJA_C_STRUKTUROSFUNKCIJOS_H

// struct for saving student information
struct Student{
    char firstName[20];
    char lastName[20];
    int courseNo;
};
typedef struct Student Student;

/*Function that prints list
IMPORTANT: There must be another subfunction (ex: printStudent below)
that prints corresponding data type to type passed*/
void printList(struct Node *node, void (*ptr)(void *));

/*function that specifically prints the Student structure declared above*/
void printStudent(void *x);

/*function that takes user input and returns a Student struct variable.
Also includes basic validation*/
Student inputStudent();

/*Uses push command from VienpusioSarasoFunkcijos.h to specifically push a
Student variable declared in StrukturosFunkcijos.h*/
void pushStudent(Node **head, Student x);

/*Uses deleteNodeGivenKey command from VienpusioSarasoFunkcijos.h to specifically delete a
Student variable by being given a key*/
void deleteStudent(Node **head, Student x);


#endif //VARTOTOJOSASAJA_C_STRUKTUROSFUNKCIJOS_H

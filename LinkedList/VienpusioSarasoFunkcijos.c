//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VienpusioSarasoFunkcijos.h"


/*Initializes list with the head pointer pointing to NULL*/
void initializeList(Node** head){
    if(head!=NULL){
        *head=NULL;
    }
}

/*Pushes variable address to the void pointer
IMPORTANT: must pass variable address to newData*/
void push(Node** head, void *newData, int data_size){
    // Allocate memory for node
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data  = malloc(data_size);
    newNode->next = (*head);

    // Copy contents of newData to newly allocated memory.
    memcpy(newNode->data, newData, data_size);


    // Change head pointer as new node is added at the beginning
    (*head) = newNode;
}

/* Function to delete the entire linked list */
void deleteList(Node** head){

    struct Node* current = *head;
    struct Node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    *head = NULL;
}

/*Returns the size (node count) of singly linked list*/
int getCurrSize(Node* head){
    int size=0;
    Node *current = head;

    while(current != NULL){
        ++size;
        current = current->next;
    }
    return size;
}

/*Inserts a node with given value after the nth node
IMPORTANT: must pass variable address to newData*/
void insertAfterNthNode(int n, void* newData, Node** head, int dataSize){
    int size = getCurrSize(*head);

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = malloc(dataSize);
    newNode->next = NULL;

    memcpy(newNode->data, newData, dataSize);

    // Can't insert if position to insert is greater than size of Linked List
    // can insert after negative pos
    if(n < 0 || n > size)
        printf("Invalid position to insert\n");

        // inserting first node
    else if(n == 0){
        newNode->next = *head;
        *head = newNode;
    }

    else
    {
        // temp used to traverse the Linked List
        Node* temp = *head;

        // traverse till the nth node
        while(n!=0){
            temp=temp->next;
            --n;
        }


        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

/*Deletes node at given position*/
void deleteNode (Node **head, int pos){
    Node* temp = *head;
    if(pos<0 || pos> getCurrSize(*head)){
        printf("Element doesn't exist\n");
        return;
    }
    int i;
    if (pos == 0) {
        *head = (*head)->next; // Advancing the head pointer
        temp->next = NULL;
        free(temp->data);
        free(temp); // Node is deleted
    }
    else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        // Now temp pointer points to the previous node of
        // the node to be deleted
        Node* del = temp->next; // del pointer points to the node
        // to be deleted
        temp->next = temp->next->next;
        del->next = NULL;
        free(del->data);
        free(del); // Node is deleted
    }

}

/*Returns address to nth value of the list, if value is not present, returns NULL*/
void *getNth(Node* head, int index){

    Node* current = head;

    int count = 0;
    while (current != NULL) {
        if (count == index)
            return current->data;
        ++count;
        current = current->next;
    }

    return NULL;
}

/*Deletes first node with given value (key)
IMPORTANT: must pass variable address to key*/
void deleteNodeGivenKey(Node** head, void *key, int data_size){
    // Store head node
    Node *temp = *head;
    Node *prev = NULL;


    // If head node itself holds the key to be deleted
    if (temp != NULL && memcmp(temp->data, key, data_size)==0) {
        *head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && memcmp(temp->data, key, data_size)!=0){
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL){
        printf("Key not present in the list.\n");
        return;
    }


    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

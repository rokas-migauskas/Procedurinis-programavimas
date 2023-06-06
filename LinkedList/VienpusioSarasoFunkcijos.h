//
// Rokas Migauskas, PS 1 kurso 4 grupe 2 pogrupis
//

#ifndef INC_4_NAMU_DARBAS_VIENPUSIOSARASOFUNKCIJOS_H
#define INC_4_NAMU_DARBAS_VIENPUSIOSARASOFUNKCIJOS_H
/* A linked list node */
struct Node{
    void *data;
    struct Node *next;
};
typedef struct Node Node;

/*Initializes list with the head pointer pointing to NULL*/
void initializeList(Node** head);

/* Function to delete the entire linked list */
void deleteList(Node** head);

/*Pushes variable address to the void pointer
IMPORTANT: must pass variable address to newData*/
void push(Node** head, void *new_data, int data_size);

/*Returns the size (node count) of singly linked list*/
int getCurrSize(Node* head);

/*Inserts a node with given value after the nth node
IMPORTANT: must pass variable address to newData*/
void insertAfterNthNode(int n, void* newData, Node** head, int dataSize);

/*Deletes node at given position*/
void deleteNode (Node **head, int pos);

/*Returns address to nth value of the list*/
void *getNth(Node* head, int index);

/*Deletes first node with given value (key)
IMPORTANT: must pass variable address to key*/
void deleteNodeGivenKey(Node** head, void *key, int data_size);


#endif //INC_4_NAMU_DARBAS_VIENPUSIOSARASOFUNKCIJOS_H

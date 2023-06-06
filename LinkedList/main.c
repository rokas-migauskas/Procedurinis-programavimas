#include <stdio.h>
#include "VienpusioSarasoFunkcijos.h"
#include <assert.h>

int main(){
    Node *head;

    // initializing list test
    initializeList(&head);
    assert(head==NULL);

    // 1st get current size of list function test
    assert(getCurrSize(head)==0);

    // push function test
    for(int i=0; i<5;++i){
        push(&head, &i, sizeof(int));
        assert((*(int *)head->data)==i);
    }

    // 2nd get current size of list function test
    assert(getCurrSize(head)==5);

    //deleting node given key test
    int temp=2;
    deleteNodeGivenKey(&head, &temp, sizeof(int));
    assert(*(int *) getNth(head, 2)!=2);

    // printing list to see how it changed
    for(int i=0; i<5;++i){
        if(getNth(head, i)!=NULL){
            printf("%d. %d\n", i+1, *(int *) getNth(head, i));
        }
    }

    // testing what happens if given key is not present in the list
    temp=40;
    deleteNodeGivenKey(&head, &temp, sizeof(int));

    // deleting node via position test
    deleteNode(&head, 0);
    assert(*(int *) getNth(head, 0)!=4);
    printf("\n");

    // printing list to see how it changed
    for(int i=0; i<5;++i){
        if(getNth(head, i)!=NULL){
            printf("%d. %d\n", i+1, *(int *) getNth(head, i));
        }
    }

    // inserting value after nth node test
    printf("\n");
    temp=20;
    insertAfterNthNode(1, &temp, &head, sizeof(int));
    assert(*(int *) getNth(head, 2)==20);

    // printing list to see how it changed
    for(int i=0; i<5;++i){
        if(getNth(head, i)!=NULL){
            printf("%d. %d\n", i+1, *(int *) getNth(head, i));
        }
    }

    // delete list function test
    deleteList(&head);
    assert(head==NULL);

    return 0;
}
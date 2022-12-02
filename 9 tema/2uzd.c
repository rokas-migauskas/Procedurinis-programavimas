#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Stack{
    int *data;
    int size;
};

typedef struct Stack Stack;

void initStack (Stack *stack);

void printStack (Stack *stack);

int getStackSize(Stack *stack);

void push(Stack *stack, int value);

int top(Stack *stack);

int pop(Stack *stack);

void destroyStack(Stack *stack);



int main(){
    Stack stack;

    initStack(&stack);
    push(&stack, 456);
    printStack(&stack);
    printf("Popped element = %d\n", pop(&stack));
    printf("Stack size = %d\n", getStackSize(&stack));
    printStack(&stack);
    destroyStack(&stack);
    printStack(&stack);
    return 0;
}
void initStack (Stack *stack){
    stack->size = 0;
    stack->data = (int *)calloc(stack->size, sizeof(int));
    return;
}
void printStack (Stack *stack){
    for(int i=0;i<(* stack).size;++i){
        printf("%d. %d\n",i+1, (* stack).data[i]);
    }

    return;
}
int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, int value){
    int temp;
    temp=stack->size;
    stack->size++;
    stack->data = (int *)realloc(stack->data, (stack->size) * (sizeof(int)));
    stack->data[temp]=value;
}

int top(Stack *stack){
    if (stack->size==0){
        return 0;
    }
    else
        return stack->data[stack->size-1];
}

int pop(Stack *stack){
    int top = top(stack);
    stack->size--;
    stack->data = (int *)realloc(stack->data, (stack->size) * sizeof(int));
    return top;
}

void destroyStack(Stack *stack){
    free(stack->data);
    initStack(stack);
}
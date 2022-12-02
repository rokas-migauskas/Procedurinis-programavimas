#include <stdio.h>
#include <stdlib.h>
#include <math.h>




struct Point{
    double x;
    double y;
};

typedef struct Point Point;

struct Stack{
    Point *data;
    int size;
};

typedef struct Stack Stack;



void initStack (Stack *stack);

void printStack (Stack *stack);

void printStackDistance (Stack *stack);

int getStackSize(Stack *stack);

void push(Stack *stack, Point value);

Point top(Stack *stack);

Point pop(Stack *stack);

void destroyStack(Stack *stack);

Point createPoint (double x, double y);

double getDistance (Point a, Point b);

void printPoint (Point p);


int main(){
    Stack stack;

    initStack(&stack);
    Point p1=createPoint(1.0, -2.0);
    Point p2=createPoint(2.0, -3.0);
    Point p3=createPoint(3.0, -4.0);
    Point p4=createPoint(4.0, -5.0);
    Point p5=createPoint(5.0, -6.0);
    push(&stack, p1);
    push(&stack, p2);
    push(&stack, p3);
    push(&stack, p4);
    push(&stack, p5);

    printStack(&stack);
    p1=pop(&stack);
    printf("Popped element = %.2lf\t %.2lf\n", p1.x, p1.y);
    printf("Stack size = %d\n", getStackSize(&stack));
    printStackDistance(&stack);
    destroyStack(&stack);
    printStack(&stack);
    return 0;
}
void initStack (Stack *stack){
    stack->size=0;
    stack->data=(Point *)calloc(stack->size, sizeof(Point));
    return;
}
void printStack (Stack *stack){
    for(int i=0;i<(* stack).size;++i){
        printf("%d. %.2lf\t %.2lf\n",i+1, (* stack).data[i].x, (* stack).data[i].y);
    }

    return;
}
int getStackSize(Stack *stack){
    return stack->size;
}

void push(Stack *stack, Point value){
    int temp;
    temp=stack->size;
    stack->size++;
    stack->data = (Point *)realloc(stack->data, (stack->size) * (sizeof(Point)));
    stack->data[temp]=value;
}

Point top(Stack *stack){
    if (stack->size==0){
        Point temp = {0.0, 0.0};
        return temp;
    }
    else
        return stack->data[stack->size-1];
}

Point pop(Stack *stack){
    Point temp;
    temp = top(stack);
    stack->size--;
    stack->data = (Point *)realloc(stack->data, (stack->size) * sizeof(Point));
    return temp;
}

void destroyStack(Stack *stack){
    free(stack->data);
    initStack(stack);
}

Point createPoint (double x, double y){
    Point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}

double getDistance(Point a, Point b){
    return sqrt(pow((a.x-b.x), 2.0)+pow((a.y-b.y), 2.0));
}

void printPoint (Point p){
    printf("Tasko koordinates: (%.2lf,%.2lf)\n", p.x, p.y);
}

void printStackDistance (Stack *stack){
    for(int i=0;i<(* stack).size;++i){
        printf("%d. %.2lf\n",i+1, sqrt(pow((stack->data[i].x), 2.0)+pow((stack->data[i].y), 2.0)));

    }
    return;
}
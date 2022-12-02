#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int swap (int *a, int *b);
int main(){
    int a=10;
    int b=20;
    printf("a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d b=%d\n", a, b);
    return 0;
}
int swap (int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}
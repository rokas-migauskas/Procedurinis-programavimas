#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *createArray(int size, int low, int high);
int main() {
    srand(time(NULL));
    int size=1000;
    int low=0;
    int high=100;
    int *array_ptr= createArray(size,low,high);
    for(int i=0;i<size;++i){
        printf("%d. %d\n", i+1, *(array_ptr+i));
    }
    return 0;
}
int *createArray(int size, int low, int high){
    int *array_ptr;
    array_ptr=calloc(size, sizeof(int));
    if (array_ptr == NULL) {
        printf("Nepavyko priskirti atminties\n");
        return -1;
    }

    for(int i=0;i<size;++i){
        *(array_ptr+i)=(rand()%(high-low+1))+low;
    }
    return array_ptr;
}
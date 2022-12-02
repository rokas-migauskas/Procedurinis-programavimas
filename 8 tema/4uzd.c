#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

int splitData(int *array, int originalArraySize, int firstPartitionSize, int **firstArrayAddress, int **secondArrayAddress);
int main() {
    int array[CAPACITY]={1,3,5,7,9,11,13,15,17,19};
    int size=CAPACITY;
    int splitIndex=7;

    int *firstArray_ptr;
    int *secondArray_ptr;

    printf("%d\n", splitData(array, size, splitIndex, &firstArray_ptr, &secondArray_ptr));

    printf("Originalus masyvas:\n");
    for(int i=0;i<size;++i){
        printf("%d. %d\n", i+1, array[i]);
    }
    //printf("%d\n", *(firstArray_ptr));

    printf("Pirmas masyvas:\n");
    for(int i=0;i<splitIndex;++i){
        printf("%d. %d\n", i+1, *(firstArray_ptr+i));
    }

    printf("Antras masyvas:\n");
    for(int i=0;i<size-splitIndex;++i){
        printf("%d. %d\n", i+1, *(secondArray_ptr+i));
    }
    free(firstArray_ptr);
    free(secondArray_ptr);

    return 0;
}
int splitData(int *array, int originalArraySize, int firstPartitionSize, int **firstArrayAddress, int **secondArrayAddress){
    // **firstArrayAddress=&firstArray_ptr
    if(firstPartitionSize>originalArraySize){
        printf("Per didelis pirmos dalies dydis\n");
        return -1;
    }

    int *firstArray_ptr;
    firstArray_ptr=(int *)calloc(firstPartitionSize, sizeof(int));
    if(firstArray_ptr==NULL){
        printf("Memory could not be allocated.\n");
        free(firstArray_ptr);
        return -1;
    }
    *firstArrayAddress=&firstArray_ptr[0];
    printf("%d\n", *firstArray_ptr);

    int *secondArray_ptr;
    secondArray_ptr=(int *)calloc((originalArraySize-firstPartitionSize), sizeof(int));
    if(secondArray_ptr==NULL){
        printf("Memory could not be allocated.\n");
        free(secondArray_ptr);
        return -1;
    }
    *secondArrayAddress=&secondArray_ptr[0];
    printf("%d\n", *secondArray_ptr);

    for(int i=0;i<firstPartitionSize;++i){
        firstArray_ptr[i]=array[i];
    }

    for(int i=firstPartitionSize;i<originalArraySize;++i){
        secondArray_ptr[i-firstPartitionSize]=array[i];
    }

    printf("%d\n", *firstArray_ptr);
    printf("%d\n", *secondArray_ptr);
    return 0;
}
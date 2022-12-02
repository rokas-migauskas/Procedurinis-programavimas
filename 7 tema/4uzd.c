#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CAPACITY 1000
void generateArray(int data[], int size, int low, int high);

int main() {
    int array[CAPACITY];
    int size = CAPACITY;
    int low = 50;
    int high = 100;
    srand(time(NULL));
    generateArray(array, size, low, high);
    for(int i=0; i<size; ++i){
        printf("%d. %d\n",i+1, array[i]);
    }
    return 0;
}
void generateArray(int data[], int size, int low, int high){
    for(int i=0; i<size; ++i){
        data[i]=rand()%(high-low+1)+low;
    }
}
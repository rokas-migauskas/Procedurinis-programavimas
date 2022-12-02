#include <stdio.h>
#define CAPACITY 10
void printArray(int array[], int size);
void insertInArray(int array[], int *size, int place, int insertValue);
void deleteFromArray(int array[], int *size, int place);
void changeArrayValue(int array[], int size, int place, int insertValue);

int main() {
    int size= CAPACITY;
    int array[CAPACITY]= {0};
    printf("b) ");
    printArray(array, size);
    array[0]=1;
    array[3]=2;
    array[9]=3;
    printf("f) ");
    deleteFromArray(array, &size, 3);
    insertInArray(array, &size, 7, 4);
    printArray(array, size);
    int x, y;
    printf("Iveskite du sveikus teigiamus skaicius (1-10).\nPirmas (1-10) nustato pakeiciama vieta masyve, antras - reiksme, i kuria pakeiciama\n");
    scanf("%d%d", &x, &y);
    changeArrayValue(array, size, x, y);
    printf("Iveskite viena skaiciu, ta vieta masyve bus pasalinta\n");
    scanf("%d", &x);
    deleteFromArray(array, &size, x);
    printf("Iveskite du sveikus teigiamus skaicius.\nPirmas (1-10) nurodo vieta, kur bus iterpiamas antras ivestas skaicius \n");
    scanf("%d%d", &x, &y);
    insertInArray(array, &size, x, y);
    printf("j) ");
    printArray(array, size);




    return 0;
}
void printArray(int array[], int size){
    printf("Masyvo reiksmes:\n");
    for(int i=0; i<size; ++i){
        printf("%d\n", array[i]);
    }
}
void insertInArray(int array[], int *size, int place, int insertValue){
    ++*size;
    for(int i=*size; i>place-1; --i){
        array[i]=array[i-1];
    }
    array[place-1]=insertValue;


}

void deleteFromArray(int array[], int *size, int place){
    for(int i=place-1; i<*size-1; ++i){
        array[i]=array[i+1];
    }
    --*size;
}

void changeArrayValue(int array[], int size, int place, int insertValue){
    array[place-1]=insertValue;
}
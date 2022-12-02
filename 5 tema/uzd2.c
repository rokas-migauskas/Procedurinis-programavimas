#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 1000
int main() {
    int array[CAPACITY]={0};
    int a, b, c;
    printf("Iveskite tris sveikus teigiamus skaicius a, b ir c:\n");
    printf("Pirmi du skaiciai sudarys reiksmiu intervala [a;b],o c - uzpildomu masyvo elementu skaicius.\n");
    scanf("%d%d%d", &a, &b, &c);
    srand(time(NULL));
    while(c>=CAPACITY){
        printf("Masyve telpa tik 1000 reiksmiu, prasome ivesti skaiciu c nuo 1 iki 1000\n");
        scanf("%d", &c);
    }
    for(int i=0; i<c; ++i){
        array[i]=rand()%(b+1)+a;
    }
    printf("Masyvo reiksmes:\n");
    for(int i=0; i<CAPACITY; ++i){
        printf("%d. %d\n", i+1, array[i]);

    }

    return 0;
}

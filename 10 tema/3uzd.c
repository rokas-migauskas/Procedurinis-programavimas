#include <stdio.h>
#include <assert.h>
#include <string.h>
char *mystrncpy(char *dest, char *source, int num);

int main() {
    char array[20];
    char* null= NULL;
    assert(mystrncpy(array, "Labas", 5)!=NULL);

    printf("%s\n", array);
    assert(strcmp(mystrncpy(array, "Labas", 3), "Lab")==0);
    assert(mystrncpy(null, "aha", 2)==NULL);
    assert(mystrncpy(array, "test", -3)==NULL);
    return 0;
}

char *mystrncpy(char *dest, char *source, int num){
    if(dest==NULL){
        return NULL;
    }
    if(num<=0){
        return NULL;
    }
    char *ptr=dest;
    while(*source!='\0' && num!=0){
        *dest=*source;
        ++dest;
        ++source;
        --num;
    }
    *dest='\0';

    return ptr;
}
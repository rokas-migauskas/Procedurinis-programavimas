#include <stdio.h>
#include <assert.h>
#include <string.h>


char *mystrcpy(char *dest, char *source);

int main() {

    char array[20];
    char *test="nenull";
    char *null=NULL;
    mystrcpy(array, "Labas");
    assert(array[6]=='\0');
    assert(mystrcpy(null, array)==NULL);
    assert(mystrcpy(array, "Labas")!=NULL && strcmp(array, "Labas")==0);
    printf("%s\n", array);
    assert(mystrcpy(array, test)!=NULL);
    printf("%s\n", array);

    return 0;
}

char *mystrcpy(char *dest, char *source){
    int index=0;
    if(dest==NULL){
        return NULL;
    }
    char *ptr= dest;
    while(*source!='\0'){
        *dest=*source;
        ++dest;
        ++source;
    }
    *dest='\0';

    return ptr;
}
#include <stdio.h>
#include <assert.h>
#include <string.h>
int compareStrings(char *a, char *b);
char *mystrstr(char *a, char *b);

int main() {
    char *array="Laba diena";
    char *test="die";
    char *notThere="asd";
    assert(strcmp(mystrstr(array, test),"diena")==0);
    printf("%s\n", strstr(array, test));
    assert(mystrstr(array, notThere)==NULL);
    return 0;
}

int compareStrings(char *a, char *b){
    while(*a!=NULL && *b!=NULL){
        if(*a!=*b){
            return 0;
        }
        ++a;
        ++b;
    }
    if(*b=='\0'){
        return 1;
    }
    else return 0;
}

char *mystrstr(char *a, char *b){
    while(*a!='\0'){
        if((*a==*b) && compareStrings(a, b)){
            return a;
        }
        ++a;
    }
    return NULL;
}
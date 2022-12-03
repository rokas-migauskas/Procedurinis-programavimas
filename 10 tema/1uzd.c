#include <stdio.h>
#include <assert.h>

size_t strlen(char *str);

int main() {

    assert(strlen("Labas")==5);
    assert(strlen("")==NULL);
    assert(strlen("\0abc")==0);

    return 0;
}

size_t strlen(char *str){
    int index=0;
    if(str==NULL){
        return 0;
    }
    while(*(str+index)!='\0'){
        ++index;
    }
    return index;
}
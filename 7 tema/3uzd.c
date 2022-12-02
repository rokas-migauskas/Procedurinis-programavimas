#include <stdio.h>

int getPositiveNumber (char *msg);
int main() {
    printf("Jusu ivestas skaicius: %d ", getPositiveNumber("Prasome ivesti skaiciu:"));
    return 0;
}

int getPositiveNumber (char *msg){
    int x;
    printf("%s\n",msg);
    while(scanf("%d", &x)!=1 || x<1 || getchar()!='\n') {
        printf("Ivestis netinka.\n");
        printf("%s\n",msg);
        scanf("%*[^\n]");
    }
    return x;
}
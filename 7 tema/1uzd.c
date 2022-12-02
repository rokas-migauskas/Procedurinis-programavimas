#include <stdio.h>

int isInRange(int number, int low, int high);
int main() {
    int a, b, c;
    printf("Iveskite sveika skaiciu a, ir dar du, kurie nurodo intervala [b,c]\n");
    scanf("%d%d%d", &a, &b, &c);
    if(isInRange(a, b, c)==1){
        printf("Telpa i intervala\n");
    }
    if(isInRange(a, b, c)==0){
        printf("Netelpa i intervala\n");
    }
    if(isInRange(a, b, c)==-1){
        printf("Klaidingas intervalas\n");
    }
    return 0;
}

int isInRange(int number, int low, int high){
    if (high<low){
        return -1;
    }
    if(number>=low && number<=high){
        return 1;
    }
    else return 0;
}

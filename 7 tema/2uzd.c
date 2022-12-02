#include <stdio.h>

unsigned long int getFactorial(int number);

int main() {
    int x;
    printf("Irasykite sveika teigiama skaiciu n, programa isves jo faktoriala\n");
    scanf("%d", &x);
    printf("Atsakymas: %lld\n", getFactorial(x));
    return 0;
}
unsigned long int getFactorial(int number){
    if (number<0) {
        return 0;
    }
    if(number==1 || number==0){
        return 1;
    }
    return number*getFactorial(number-1);
}
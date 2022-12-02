#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, nextNumber;
    printf("Iveskite tris sveikus neneigiamus skaicius\n");
    scanf("%d%d%d",&a, &b, &c);
    printf("Ivesti skaiciai: a=%d b=%d c=%d\n",a, b, c);
    for(int i=0; i<c-2; ++i){
        nextNumber=a+b;
        a=b;
        b=nextNumber;
    }
    printf("c-asis sekos narys: %d\n", nextNumber);



    return 0;
}

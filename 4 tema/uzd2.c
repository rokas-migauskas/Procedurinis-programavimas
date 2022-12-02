#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, kiekis=0;
    printf("Iveskite tris sveikus skaicius (a;b] - intervalas, c - daliklis kiekvienam sveikam skaiciuj intervale\n");
    scanf("%d%d%d",&a, &b, &c);
    printf("Teigiami skaiciai intervale(%d;%d], kurie dalinasi is %d su liekana 1:\n", a, b, c);
    for(int i=a+1; i <= b; ++i){
        if(i%c==1){
            printf("%d\n",i);
            kiekis++;
        }
    }
    if(kiekis==0){
        printf("Tokiu skaiciu nera intervale (%d;%d]", a, b);
    }

    return 0;
}

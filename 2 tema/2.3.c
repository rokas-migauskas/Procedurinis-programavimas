//PS 4 grupe, 2 pogrupis, Rokas Migauskas, email - rokas.migauskas@mif.stud.vu.lt
#include <stdio.h>

int main() {
    int sk;
    char atsakymas[]="";
    printf("Iveskite sveika skaiciu:\n");
    scanf("%d",&sk);
    (sk%2==0)? (strcpy(atsakymas, "Lyginis")):(strcpy(atsakymas, "Nelyginis"));
    printf("%s",atsakymas);
    return 0;
}

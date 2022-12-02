#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("Iveskite tris sveikus skaicius (a, b ir c koeficientai kvadratines lygties)\n");
    scanf("%d%d%d",&a, &b, &c);
    double diskriminantas;
    diskriminantas=pow(b,2)-4*a*c;
    //tikrinu sprendiniu skaiciu pagal diskriminanta
    if(diskriminantas>0){
        printf("Sprendiniu skaicius: %d\n", 2);
        printf("Sprendiniai: %.2f, %.2f\n",(-b+sqrt(diskriminantas))/(2*a), (-b-sqrt(diskriminantas))/(2*a));
    }
    else if(diskriminantas==0){
        printf("Sprendiniu skaicius: %.2f\n", -b/(2*a));
    }
    else printf("Sprendiniu skaicius: %d\n", 0);






    return 0;
}

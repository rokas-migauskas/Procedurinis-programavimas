//PS 4 grupe, 2 pogrupis, Rokas Migauskas, email - rokas.migauskas@mif.stud.vu.lt
#include <stdio.h>
#include <math.h>
int main() {
    double x,y,z;
    double atsA;
    double atsB;
    printf("Iveskite tris realiuosius skaicius:");
    scanf("%lf %lf %lf",&x,&y,&z);
    atsA=x+4*y+pow(z,3);
    atsB=(x+sqrt(y))*(pow(z,4)-abs(z)+46.3);
    printf("a)%f\nb)%f",atsA,atsB);
    return 0;
}

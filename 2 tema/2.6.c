//PS 4 grupe, 2 pogrupis, Rokas Migauskas, email - rokas.migauskas@mif.stud.vu.lt
#include <stdio.h>
#include <math.h>
int main() {
    int x,y,z;
    int max,min;
    printf("Iveskite tris sveikus skaicius:");
    scanf("%d %d %d",&x,&y,&z);
    //didziausios reiksmes ieskojimas
    max=((x+y)+abs(x-y))/2;
    max=((max+z)+abs(max-z))/2;
    printf("Didziausias: %d",max);

    return 0;
}

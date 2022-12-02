#include <stdio.h>
#include <math.h>
#include <float.h>
#define CAPACITY 1000
int main() {
    int n;
    double s;
    printf("Iveskite du skaicius s ir n:\n");
    scanf("%lf%d",&s ,&n);
    double array[n];
    int i=0;
    double temp;
    while(i<n) {
        printf("Iveskite teigiama skaiciu:\n");
        scanf("%lf", &temp);
        if (temp < 0) {
            printf("Neigiamu reiksmiu negali buti.\n");
            continue;
            }
        array[i] = temp;
        ++i;
        }
        int count=1;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(abs((array[i]*array[j]-s))<=0.00001){
                    printf("%d pora: %.2lf, %.2lf\n", count, array[i], array[j]);
                    ++count;
                }
            }
        }

    return 0;
}
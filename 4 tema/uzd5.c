#include <stdio.h>
#include <math.h>



int main() {
    int n;
    double avg, sum=0;
    double max, min, temp;
    printf("Kiek skaiciu sudarys seka?\n");
    scanf("%d", &n);
    printf("Ivedete: %d\n",n);
    printf("Iveskite 1 skaiciu\n");
    scanf ("%lf", &temp);
    printf("%Ivedete: lf\n",temp);
    sum=sum+temp;
    max=temp;
    min=temp;
    for(int i=1; i<n; ++i){
        printf("Iveskite %d skaiciu:\n", i+1);
        scanf ("%lf", &temp);
        printf("Ivedete: %lf\n",temp);
        sum=sum+temp;
        if (temp>max){
            max=temp;
        }
        if(temp<min){
            min=temp;
        }
    }
    avg=sum/n;
    printf("Suma: %.3lf\n", sum);
    printf("Vidurkis: %.3lf\n", avg);
    printf("Didziausia reiksme: %.3lf\n", max);
    printf("Maziausia reiksme: %.3lf\n", min);




    return 0;
}


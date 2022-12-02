#include <stdio.h>
#include <float.h>
#include <math.h>
int postDecimalDigitCount(double num);
int main() {
    double num;
    char filename[256];
    FILE *fp;
    fp=fopen("in.txt", "r");
    while(fscanf(fp, "%lf", &num)!=1 || (num>1000 || num<10) || postDecimalDigitCount(num)>3){

        printf("Netinkama ivestis, prasome ivesti kito failo pavadinima formatu name.txt\n");
        scanf("%s", filename);
        fp=fopen(filename, "r");
    }
    printf("%d\n", postDecimalDigitCount(num));
    printf("%lf\n", num);
    fclose(fp);
    return 0;
}
int postDecimalDigitCount(double num){
    int count=0;

    while(num- floor(num)>0.0001){
        num=num*10;
        ++count;
    }
    return count;
}
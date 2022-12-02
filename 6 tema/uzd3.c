#include <stdio.h>
#include <string.h>
int validation (char semicolon[], char enter);
int fileValidation (char line[]);
double midValue (double a, double b, double c);
int main() {
    printf("Si programa randa vidurini (pagal reiskme) skaiciu is triju.\n");
    printf("Prasome ivesti tris skaicius, atskirtus kabliataskiais, be tarpu:\n");
    double a, b, c;
    double middle;
    double check;
    char line[256];
    char semicolon[2];
    char enter;
    while(1){
       fgets(line, sizeof line, stdin);
       check= sscanf(line, "%lf%c%lf%c%lf%c", &a, &semicolon[0], &b, &semicolon[1], &c, &enter);
       if(check==6 && validation(semicolon, enter)==1){
           break;
       }
       printf("Netinkama ivestis\n");
    }
    middle= midValue(a, b, c);
    while(1){
        printf("Prasome ivesti falio varda su pabaiga .txt, kuriame bus rezultatai:\n");
        scanf("%s", &line);
        if(fileValidation(line)==1){
            break;
        }
        printf("Netinkama ivestis\n");
    }
    FILE *fp;
    fp= fopen(line, "w");
    fprintf(fp, "Vidurine reiksme:\n%lf", middle);
    fclose(fp);


    return 0;
}
int validation (char semicolon[], char enter){
    if(semicolon[0]==';' && semicolon[1]==';' && enter=='\n'){
        return 1;
    }
    return 0;
}
double midValue (double a, double b, double c){
    if((b>a && b<c) || (b>c && b<a)){
        return b;
    }
    else if((a>b && a<c) || (a>c && a<b)){
        return b;
    }
    else return c;
}
int fileValidation (char line[]){
    if(strstr(line, ".txt")!=0){
        return 1;
    }
    else return 0;
}
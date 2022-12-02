#include <stdio.h>
#include <string.h>
int emailValidation (char line[]);
int main() {
    char line[256];
    printf("Iveskite el.pasto adresa:\n");
    while( scanf("%s", &line)!=1 || emailValidation(line)!=1){
        printf("%s\n",line);
        printf("Netinkama ivestis.\n");
        printf("Iveskite el.pasto adresa:\n");
    }
    FILE *fp;
    fp=fopen("emails.txt", "a");
    strtok(line, "@");
    fprintf(fp, "%s\n", strtok(NULL, "@"));
    printf("Sekmingai ivykdyta, domeno ieskokite faile emails.txt programos direktorijoje");



    return 0;
}
int emailValidation (char line[]){
    int atLocation=-1;
    int dotLocation=-1;
    int preAtCount=0, postAtCount=0, postDotCount=0;
    // randu kur @
    for(int i=0; i<strlen(line); ++i){
        if(line[i]=='@'){
            atLocation=i;
        }
    }
    // randu kur .
    for(int i=0; i<strlen(line); ++i){
        if(line[i]=='.'){
            dotLocation=i;
        }
    }
    if(atLocation==-1 || dotLocation==-1){
        return 0;
    }

    for(int i=0; i<atLocation; ++i){
        ++preAtCount;
    }
    for(int i=atLocation; i<dotLocation; ++i){
        ++postAtCount;
    }
    for(int i=dotLocation; i<strlen(line); ++i){
        ++postDotCount;
    }
    if(preAtCount!=0 && postAtCount!=0 && postDotCount!=0){
        return 1;
    }
    else return 0;
}
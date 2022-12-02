#include <stdio.h>
#include <math.h>
#include <string.h>

int digitCount(char temp[]);

int main() {
    int max=0;
    char temp[80];
    char ans[80];
    while(1){
        printf("Iveskite skaiciu (pirma neteigiama reiksme zymi pabaiga)\n");
        scanf("%s", &temp);
        printf("%s\n", temp);
        printf("%d\n", digitCount(temp));
        if(digitCount(temp)>max){
            max= digitCount(temp);
            strcpy(ans, temp);
        }
        if(temp[0]=='-'){
            break;
        }

    }
    printf("Daugiausiai skaitmenu turintis skaicius: %lf\n",ans);



    return 0;
}

int digitCount(char temp[]){
    int count=0;
    int i=0;
    while(temp[i]!='\0'){
        if(temp[i]>=48 && temp[i]<=57){
            ++count;
        }
        ++i;
    }
    return count;
}

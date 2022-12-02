//PS 4 grupe, 2 pogrupis, Rokas Migauskas, el.pastas - rokas.migauskas@mif.stud.vu.lt
//Per sunki aritmetika, pasiilgau masyvu. Kaip padaryt su long int nepagaunu
#include <stdio.h>
#include <math.h>

int numberLength (int num);
int main() {
    int length;
    long int num;
    printf("Iveskite sveika skaiciu, prasau neperzengt 32bit limito\n");
    scanf("%ld",&num);
    int neg;
    //tikrinu ar neigiamas, jei neigiamas, imu moduli ir gale padauginu is -1
    if(num<0){
        num=abs(num);
        neg=1;
    }
    else neg=0;
    length= numberLength(num);
    printf("%d\n",length);
    int maxDigit=-1;
    long int newNum=0,tempNum,remainder;
    int lastDigit, newLength,place;
    tempNum=num;
    newLength=length;
    for(int i=0;i<length;i++){
        for(int j=0;j<newLength;j++){
            lastDigit=tempNum%10;
            tempNum=tempNum/10;
            if(lastDigit>maxDigit){
                maxDigit=lastDigit;
                place=j;
            }
        }
        newNum=newNum*10+maxDigit;
        remainder=num%(int)pow((double)10,(double)place);
        num=num/(int)pow((double)10,(double)place+1);
        num=num*(int)pow((double)10,(double)place)+remainder;
        tempNum=num;
        newLength--;
        maxDigit=-1;
    }
    if(neg==1){
        printf("%ld\n",newNum*(-1));
    }
    else printf("%ld\n",newNum);
    return 0;
}
int numberLength (int num){
    int length=0;
    while(num>0) {
        num = num / 10;
        length++;
    }
    return length;
}
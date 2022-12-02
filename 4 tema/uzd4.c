#include <stdio.h>
#include <math.h>

int biggestNumber(int a, int b, int c);

int main() {
    int a, b, c;
    int DBD=0, MBK=0, largestNum;
    printf("Iveskite tris sveikus neneigiamus skaicius\n");
    scanf("%d%d%d",&a, &b, &c);
    printf("Ivesti skaiciai: a=%d b=%d c=%d\n",a, b, c);
    largestNum= biggestNumber(a,b,c);
    //DBD ieskojimas
    for(int i=1; i<largestNum; ++i){
        if(a%i==0 && b%i==0 && c%i==0){
            DBD=i;
        }
    }
    for(int i=largestNum; i>0; i--){
        if(i%a==0 && i%b==0 && i%c==0){
            MBK=i;
        }
    }
    //MBK ieskojimas
    printf("DBD: %d\n", DBD);
    printf("MBK: %d\n", MBK);


    return 0;
}

int biggestNumber(int a, int b, int c){
    int max=c;
    if (max<b){
        max=b;
    }
    if(max<a){
        max=a;
    }
    return max;
}
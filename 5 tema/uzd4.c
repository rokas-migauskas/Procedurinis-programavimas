#include <stdio.h>
#define CAPACITY 1000

int isPrime(int num);
int checkIfPresent(int array[], int num, int count);

int main() {
    int usedPrimes[CAPACITY];
    int temp, count=0;
    printf("Iveskite sveikus teigiamus skaicius viena po kito, programa atrinks pirminius skaicius (seka uzbaikite neteigiamu skaiciumi)\n");
    while(1){
        printf("Iveskite sveika skaiciu:\n");
        scanf("%d", &temp);
        if(temp<=0){
            break;
            }
        if(count==CAPACITY){
            printf("Perzengtas skaiciu limitas\n");
            break;
        }
        if(isPrime(temp)==1 && checkIfPresent(usedPrimes, temp, count)==0){
                usedPrimes[count]=temp;
                ++count;
            }
        }
    printf("Pirminiai skaiciai:\n");
    for(int i=0; i<count; ++i){
        printf("%d. %d\n", i+1, usedPrimes[i]);
    }

    return 0;
}

int isPrime(int num){
    if(num==1){
        return 0;
    }
    for(int i=2; i<(num/2)+1; ++i){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}
int checkIfPresent(int array[], int num, int count){
    for(int i=0; i<=count; ++i){
        if(array[i]==num){
            return 1;
        }
    }
    return 0;
}
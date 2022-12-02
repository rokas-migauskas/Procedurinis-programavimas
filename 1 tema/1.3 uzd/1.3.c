//PS 4 grupe, 2 pogrupis, Rokas Migauskas, email - rokas.migauskas@mif.stud.vu.lt
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values

// input:
//    user enters 10 non-negative integers
// output:
//    report how many times each unique value occured,
//    display values and occurence times in ascending order

int main() {

   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;

   printf("Irasykite 10 skaiciu, ir is to si programa isves ju pasikartojimo dazni\n");

   printf("Irasykite 10 skaiciu nuo 0 iki 1000 (irasius spauskite enter)\n");

   while(counter < SIZE){
      printf("Iveskite %d sekos nari\n",counter+1);
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <= FREQ_SIZE)){
            inputArray[counter++] = num;
            printf("Numeris sekmingai ivestas\n");
         } else {
            printf("Netelpa i rezius [0,%d]\n",FREQ_SIZE);
         }
      } else {
         printf("Netinkamas skaicius, prasome ivesti sveika, neneigiama skaiciu");
         while(getchar() != '\n')
            ;
      }
   }

   printf("Duomenys tinkamai ivesti\n");

   // proceeding to computations...

   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i]-1 ]++;
   }

   int flag;
   int diffNumsCounter = 0;

   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }
      }
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }

   int temp;

   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }

   printf("Rezultatai: \n");
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i]-1 ] != 0 ){
         printf("%8d.............%d\n",diffNums[i],frequency[diffNums[i]-1]);
      }
   }

   return 0;
}

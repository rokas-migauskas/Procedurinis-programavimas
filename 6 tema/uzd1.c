#include <stdio.h>

int main() {
    int n;
    long long int factorial=1;
    FILE *fp;
    fp=fopen("rez1.txt","w");
    printf("Iveskite teigiama sveika skaiciu, duomenu faile rez1.txt programos direktorijoje bus to skaiciaus faktorialas\n");
    while(scanf("%d", &n)!=1 || getchar()!='\n' || n<0){
       printf("Netinkama reiksme, prasome ivesti teigiama sveika skaiciu\n");
       scanf("%*[^\n]");
    }
    for(int i=n; i>=1; --i){
        factorial=factorial*i;
    }
    fprintf(fp, "%lld", factorial);
    fclose(fp);

    return 0;
}

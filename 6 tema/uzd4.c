#include <stdio.h>
int textValidation(char dash[], char enter, int year, int month, int day);
int weekday (int year, int month, int day);
int main() {
    int year, month, day;
    char dash[2];
    char enter;
    printf("Programos aplanke sukurkite faila week.txt, kuriame turi buti surasytos savaites dienos atskirose eilutese\n");
    printf("Prasome irasyti data formatu YYYY-MM-DD, programa grazins savaites diena.\n");
    while(scanf("%d%c%d%c%d%c", &year, &dash[0], &month, &dash[1], &day, &enter)!=6 || textValidation(dash, enter, year, month, day)==0){
        printf("Netinkama ivestis\n");
        printf("Prasome irasyti data formatu YYYY-MM-DD, programa grazins savaites diena.\n");
    }
    FILE *fp;
    fp= fopen("week.txt", "r");

    char weekdays[7][100];
    for(int i=0; i<7; ++i){
        fscanf(fp, "%s", &weekdays[i][0]);
    }
    printf("Savaites diena:\n%s", weekdays[weekday(year, month, day)]);
    fclose(fp);

    return 0;
}
int textValidation(char dash[], char enter, int year, int month, int day){
    int symbolFlag=0;
    int dateFlag=1;
    if(dash[0]=='-' && dash[1]=='-' && enter=='\n'){
        symbolFlag=1;
    }
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(year%4==0){
        daysInMonth[1]=29;
    }
    if(month>12 || month<0){
        dateFlag=0;
    }
    for(int i=0; i<12; ++i){
        if(day>daysInMonth[month] || day<1){
            dateFlag=0;
        }
    }
    if(dateFlag==1 && symbolFlag==1){
        return 1;
    }
    else return 0;

}
int weekday (int year, int month, int day){
    // idk what the fuck this is, copied it
    int weekday;
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    weekday= (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    weekday=weekday+6;
    if(weekday>6){
        weekday=weekday-7;
    }
    return weekday;
}
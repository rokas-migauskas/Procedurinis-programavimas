#include <stdio.h>


long getFileSize(char *fileName);
int main() {

    printf("Failas uzima %d baitu.\n", getFileSize("test.txt"));
    return 0;
}

long getFileSize(char *fileName){
    FILE *fp;
    long size;
    fp=fopen(fileName, "rb");
    if( fp == NULL )  {
        perror ("Error opening file");
        return(-1);
    }
    fseek(fp, 0, SEEK_END);
    size=ftell(fp);
    fclose(fp);
    return size;
}

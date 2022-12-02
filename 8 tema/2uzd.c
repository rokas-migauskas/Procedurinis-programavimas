#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *maxByteFile(int argc, char **argv);
long getFileSize(char *fileName);

int main(int argc, char *argv[]){

    printf("%s\n", maxByteFile(argc,argv));
    return 0;
}

char *maxByteFile(int argc, char **argv){
    int maxBytes=-1;
    int maxByteIndex=-1;

    for(int i=2;i<argc;++i){

        if(getFileSize(argv[i])>maxBytes){
            maxBytes= getFileSize(argv[i]);
            maxByteIndex=i;
        }
    }
    return argv[maxByteIndex];
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
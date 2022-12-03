#include <stdio.h>
#include <assert.h>
void *memcpy(void *dest, void *source, int num);
struct testStruct{
    int x;
    char y;
    double z;
}test, copyTest;


int main() {
    int intArray[5]={1,2,3,4,5};
    int testIntArray[5];

    test.y='a';
    test.x=2;
    test.z=4.2;
    char *nullSource=NULL;
    char *nullDest=NULL;

    assert(memcpy(testIntArray, intArray, sizeof(int)*5)!=NULL);
    for(int i=0;i<5;++i){
        printf("%d\n", testIntArray[i]);
    }
    assert(memcpy(&copyTest, &test, sizeof(test))!=NULL);
    assert(copyTest.x==2 && copyTest.y=='a'&&copyTest.z==4.2);
    printf("%d %c %lf\n", copyTest.x, copyTest.y, copyTest.z);
    assert(memcpy(nullDest, intArray, 5)==NULL);
    assert(memcpy(intArray, nullSource, 5)==NULL);
    assert(memcpy(intArray, testIntArray, -5)==NULL);

    return 0;
}

void *memcpy(void *dest, void *source, int num){
    if(num<=0){
        return NULL;
    }
    if(dest==NULL || source==NULL){
        return NULL;
    }
    char *csrc = (char *)source;
    char *cdest = (char *)dest;

    while(num!=0){
        *cdest=*csrc;
        ++cdest;
        ++csrc;
        --num;
    }
    return dest;

}
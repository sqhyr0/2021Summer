#include<stdio.h>
#include<stdlib.h>
int* getRow(int rowIndex, int* returnSize){
    int* res=(int*)malloc(sizeof(int)*(rowIndex+1));//注意，rowIndex从0开始
    res[0]=1;
    for(int i=1;i<rowIndex+1;i++)
        res[i]=(long long)res[i-1]*(rowIndex-i+1)/i;
    return res;
}

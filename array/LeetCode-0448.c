#include<stdio.h>
#include<stdlib.h>
// 1  3  3  4  5
// 0  1  2  3  4
//-1  3 -3 -4 -5 

#include<string.h>
#include<math.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {//利用自身作为一个哈希表，空间复杂度为O(1)
        int temp=fabs(nums[i])-1;
        if(nums[temp]<0)continue;
        else nums[temp]*=-1;//将值改为负数以此来对num[i]进行标记
    }
    int* ret =(int*) malloc(sizeof(int) * numsSize);
    *returnSize = 0;//本地测试时显示此处有错误，而上传答案时一切正常
    for (int i = 0; i < numsSize; i++) {
          if(nums[i]>0)  
            ret[(*returnSize)++] = i + 1;
    }
    return ret;
}
int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    int *returnSize;
    int* arr=findDisappearedNumbers(nums,numsSize,returnSize);
    for(int i=0;i<*returnSize;i++)printf("%d ",arr[i]);
}
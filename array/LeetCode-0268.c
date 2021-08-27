#include<stdio.h>
int missingNumber(int* nums, int numsSize){
    unsigned long sum=0;//为避免数值溢出，选择最大的整数类型
    for(int i=0;i<numsSize;i++)sum+=nums[i];
    return (numsSize*(numsSize+1))/2-sum;
}
int main()
{
    int nums[10000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    printf("%d",missingNumber(nums,numsSize));
}
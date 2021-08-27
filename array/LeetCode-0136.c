/*
*只出现一次的数字
*利用位运算
*a^a=0;a^0=a;异或运算满足交换律和结合律
*/
#include<stdio.h>
int singleNumber(int* nums, int numsSize){
    int res=0;//由a^0=a，将res初始化为0而非一般情况下的1
    for(int i=0;i<numsSize;i++)res=res^nums[i];
    return res;
}
int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    printf("%d",singleNumber(nums,numsSize));
}
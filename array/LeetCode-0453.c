#include<stdio.h>

int minMoves(int* nums, int numsSize)
{
    int res=0,min=nums[0];
    for(int i=0;i<numsSize;i++)if(min>nums[0])min=nums[0];
    for(int i=0;i<numsSize;i++)res+=nums[0]-min;
    return res;
}
int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    printf("%d",minMoves(nums,numsSize));
}
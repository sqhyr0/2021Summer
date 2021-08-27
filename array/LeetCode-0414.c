/*
返回第三大的数
从集合中剔除最大的数，重复三次
理论上时间复杂度为O(n)
*/
#include<stdio.h>
int thirdMax(int* nums, int numsSize){
    int first,second,third;
    first=second=third=0x80000000;
    int flag=0;
    for(int i=0;i<numsSize;i++)
    {
        if(first<nums[i])
        {
            first=nums[i];
            flag++;
        }
    }
    if(!flag)return first;
    flag=0;
    for(int i=0;i<numsSize;i++)
    {
        if(second<nums[i]&&nums[i]!=first)
        {
            second=nums[i];
            flag++;
        }
    }
    if(!flag)return first;
    flag=0;
    for(int i=0;i<numsSize;i++)
    {
        if(third<=nums[i]&&nums[i]!=first&&nums[i]!=second)
        {
            third=nums[i];
            flag++;
        }
    }
    if(!flag)return second;
    return third;

}

int main()
{
    int nums[10000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    printf("%d",thirdMax(nums,numsSize));
}
/*
最大子序和，动态规划总结
对于一个给定的数组中的任意元素i，以其为尾端的子序列有若干个
记其中最大的那个子序列为f(i)；
对于[0,len-1]中的每个f(i)，选其中的最大者，作为最大子序列，其和即为所求
故，全流程中有两次“最大”
而对于一个f(i)，有递推定义:f(i)=max{f(i-1)+nums[i],nums[i]},f(0)=nums[0];
*/
#include<stdio.h>
int maxSubArray(int* nums, int numsSize){
    int res=nums[0];//res中储存当前的最大子序列和
    int max=nums[0];//max储存f(i)的值
    for(int i=1;i<numsSize;i++)
    {
        max=max+nums[i]>nums[i]?max+nums[i]:nums[i];
        res=max>res?max:res;
    }
    return res;
}
int main()
{
    int arr[1000];
    int i=0;
    while(scanf("%d",&arr[i])!=EOF)i++;
    printf("%d",maxSubArray(arr,10));
}
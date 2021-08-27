/*
最小操作次数使元素相等
进阶版
仅需一次遍历
对于每个nums[i]
nums[i]>min时，该元素自身到达min的距离为nums[i]-min，故res只需加上num[i]-min，对其它元素无影响
nums[i]<min时，该元素成为新的min，此时nums[i]之前的所有元素，其对于min的距离发生改变
此前，res=∑(nums[]-min)，min改变后，每个距离多出了min-nums[i]，故res+=(min-nums[i])*i
*/
#include<stdio.h>
int minMoves(int* nums, int numsSize){
    int min=nums[0],res=0;
    for(int i=0;i<numsSize;i++)
    {
        if(min>nums[i])
        {
            res+=(min-nums[i])*i;
            min=nums[i];
        }
        else res+=nums[i]-min;
    }
    return res;
}

int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    printf("%d",minMoves(nums,numsSize));
}
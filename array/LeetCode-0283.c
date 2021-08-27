/*
移动零
使用双指针法，原地改动
两指针只遍历一次，未申请额外的数组空间，故时间复杂度为O(n)，空间复杂度为O(1)
两指针将数组分为三部分
left左侧为已作处理的区域，不再变化，left直接指向的位置将是下一个非0元素的存入位置
left与right之间的区域，其长度即为当前已检测出的0的数量
right右侧的区域为待检测的区域
*/
void moveZeroes(int* nums, int numsSize){
    int left=0,right=0;//设置两个双指针，从数组首部开始
    for(right;right<numsSize;right++)
    {
        if(nums[right])
        {
            nums[left]=nums[right];
            left++;
        }
    }
    for(left;left<numsSize;left++)nums[left]=0;
}
#include<stdio.h>
int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize))numsSize++;
    moveZeroes(nums,numsSize);
    for(int i=0;i<numsSize;i++)printf("%d ",nums[i]);
}
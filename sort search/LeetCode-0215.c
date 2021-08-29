/*
第k大的数
快速选择法，时间复杂度为O(logn),空间复杂度为O(logn)
直观的想法是先对数组元素进行排序，随后找出对应的元素，这样做的时间复杂度为O(n*logn)，是排序时花费的时间
改进：
对于快速排序，每次选出一个中间元素，这个元素的位置在数组中是固定的
一次快排后，对这个选出来的中间元素的位置进行判断
若位置刚好为第k大的元素的位置，则直接返回该元素的值
若小于，则再在该元素右边的一半区域进行一次快排
若大于，则再在该元素左边的一半区域进行一次快排
这样，每次排序仅对一半的区域进行操作，时间复杂度降低到了O(logn)
*/

#include<stdio.h>
#include<stdlib.h>
int res;
void quickSort(int* nums,int left,int right,int pos)
{
    res=left;
    if(left<right)
    {
        int l=left,r=right;
        int temp=nums[left];
        while(l<r)
        {
            while(l<r&&temp<=nums[r])r--;
            if(l<r)nums[l++]=nums[r];
            while(l<r&&temp>=nums[l])l++;
            if(l<r)nums[r--]=nums[l];
        }
        nums[l]=temp;

        if(l==pos)res=nums[l];
        else if(l>pos)quickSort(nums,left,l-1,pos);
        else quickSort(nums,l+1,right,pos);
    }
}
int findKthLargest(int* nums, int numsSize, int k){
    quickSort(nums,0,numsSize-1,numsSize-k);
    return res;
}

int main()
{
    int nums[1000];
    int numsSize=0;
    while(scanf("%d",nums+numsSize)!=EOF)numsSize++;
    int k;
    scanf("%d",&k);
    printf("%d",findKthLargest(nums,numsSize,k));
}
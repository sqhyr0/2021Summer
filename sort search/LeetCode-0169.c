#include<stdio.h>
#include<stdlib.h>
/*
多数元素
排序后返回返回数组中中间位置的值，时间复杂度为O(nlogn)，空间复杂度为O(logn)
使用快排超时，故使用库函数qsort，qsort针对不同的情形作出优化，比自己编写的排序算法更高效
需要注意的是回调函数中的变量要先进行类型转化
*/
/*void quickSort(int* nums,int left,int right)
{
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
        quickSort(nums,left,l-1);
        quickSort(nums,l+1,right);
    }
}*/
int compare(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int majorityElement(int* nums, int numsSize){
    //quickSort(nums,0,numsSize-1);
    qsort(nums,numsSize,sizeof(int),compare);
    return nums[(numsSize)/2];
}

int main()
{
    int nums[100];
    int numsSize=0;
    while(scanf("%d",&nums[numsSize])!=EOF)numsSize++;
    printf("%d ",majorityElement(nums,numsSize));
}
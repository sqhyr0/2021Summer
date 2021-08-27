/*
删除数组中的重复项
所给数组为有序数组
由于数组有序，重复项必定是成块分布，不会出现四散在数组中的情况
此时，对于任意的arr[i]，满足arr[i]!=arr[i-1]时，arr[i]即为一个用于覆盖掉重复元素的元素
使用双指针法，时间复杂度为O(n)
两指针从第1项开始向后移动
主指针向后依次遍历，副指针指向每个将被覆盖的元素
若主指针所指元素满足上述不等式，将主指针所指元素赋值给副指针所指区域。
*/
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
    if(!numsSize)return 0;
    int i,j;
    i=j=1;
    for(i;i<numsSize;i++)
    {
        if(nums[i]>nums[i-1])
        {
            nums[j]=nums[i];
            j++;
        }
    }
    return j;

}
int main()//测试用主函数
{
    int arr[1000];
    int i=0;
    while(scanf("%d",&arr[i])!=EOF)i++;
    int len=10-removeDuplicates(arr,10);
    for( i=0;i<len;i++)printf("%d ",arr[i]);
}
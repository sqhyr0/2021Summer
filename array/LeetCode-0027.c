#include<stdio.h>
//3223 2223
/*int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0)return 0;
    int i,j;
    i=0;
    j=numsSize-1;
    for(i;i<=j;i++)
    {
        if(nums[i]==val)
        {
            while(nums[j]==val&&j>i)j--;
            nums[i]=nums[j];
            j--;
            //nums[j]=val;
        }
    }
    return j+1;
}*/
int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize==0)return 0;
    int left,right;
    for(left=0,right=0;right<numsSize;right++)
    {
        if(nums[right]!=val)
        {
            nums[left]=nums[right];
            left++;
        }
    }
    return left;
}
int main()
{
    int arr[1000];
    int i=0;
    while(scanf("%d",&arr[i])!=EOF)i++;
    int val;
    scanf("%d",&val);
    int len=removeElement(arr,4,val);
    for(int i=0;i<len;i++)printf("%d ",arr[i]);
}
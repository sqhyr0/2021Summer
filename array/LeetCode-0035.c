#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    if(nums[right] < target) return numsSize;
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main()
{
    int arr[100];
    int i=0;
    while(scanf("%d",&arr[i])!=EOF)i++;
    int val;
    scanf("%d",&val);
    printf("%d",searchInsert(arr,4,val));

}
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void preOrder(struct TreeNode* T);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
struct TreeNode* inOrderCreate(int *nums,int left,int right);

int main()
{
    int arr[1000];
    int i=0;
    while(scanf("%d",arr+i)!=EOF)i++;
    preOrder(sortedArrayToBST(arr,i));
}

struct TreeNode* inOrderCreate(int *nums,int left,int right)
{
    if(left>right)return NULL;
    else
    {
        struct TreeNode* T=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        int mid=(left+right)/2;
        T->val=nums[mid];
        T->left=inOrderCreate(nums,left,mid-1);
        T->right=inOrderCreate(nums,mid+1,right);
        return T;
    }
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return inOrderCreate(nums,0,numsSize-1);
}
void preOrder(struct TreeNode* T)
{
    if(T)
    {
        printf("%d ",T->val);
        preOrder(T->left);
        preOrder(T->right);
    }
}
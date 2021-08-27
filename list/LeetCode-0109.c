/*
有序链表转化为二叉搜索树
双指针+递归法，时间复杂度为O(nlogn)，空间复杂度为O(n)
由题目可知，链表升序
在构造二叉树时，保证根节点的值始终为对应段链表的中间节点的值即可
设置两个指针left和right，用来约束递归函数中待操作链表的区间，区间为[left，right)
这是因为单项链表中，很容易到达一个链表的后继，而找到其前驱的流程却很复杂
使用快慢指针法找到一段链表中的中间节点，为传入函数的根节点指针申请空间并赋值
随后将[left,mid)，和[mid->next,right)作为新的链表区间传入下一个函数
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

struct TreeNode* fuc(struct ListNode* left,struct ListNode* right)
{
    if(left==right)return NULL;
    struct ListNode* fast=left,*slow=left;
    while(fast!=right&&fast->next!=right)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    struct TreeNode* T=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->val=slow->val;
    T->left=fuc(left,slow);
    T->right=fuc(slow->next,right);
    return T;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL)return NULL;
    struct TreeNode* T;
    struct ListNode* left=head,*right=head;
    while(right!=NULL)right=right->next;
    T=fuc(left,right);
    return T;
}

void preOrderTraverse(struct TreeNode* T)
{
    if(T!=NULL)
    {
        printf("%d ",T->val);
        preOrderTraverse(T->left);
        preOrderTraverse(T->right);
    }
    else printf("null ");
}
int main()
{
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    int temp;
    struct ListNode* p=head;
    while(scanf("%d",&temp)!=EOF)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=temp;
        p->next=NULL;
    }
    struct TreeNode* T=sortedListToBST(head->next);
    preOrderTraverse(T);
}
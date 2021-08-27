/*
删除链表中的重复元素
双指针向后遍历即可
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL)return head;
    struct ListNode *right=head->next,*left=head;
    while(right)
    {
        if(right->val==left->val)
        {
            while(right&&right->val==left->val)right=right->next;
            left->next=right;
            left=right;
        }
        else
        {
            left=left->next;
            right=right->next;
        }
    }
    return head;
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
    head=deleteDuplicates(head->next);
    p=head;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
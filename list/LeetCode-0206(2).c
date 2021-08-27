/*
翻转链表，双指针法
比之递归法，更加简洁，且空间复杂度为O(1)，时间复杂度同样为O(n)
设置两个指针，从前往后依次扫描，将主指针的后继指向它的前驱(即副指针所指节点)
需要注意的是，其实还需要一个指针来储存主指针的后继地址，在主指针的后继改变后，无法按照常规直接通过所指节点的尾指针直接向后移动
副指针的移动也不能通过所指节点的尾指针直接向后移动，而应该直接跳跃到主指针所指节点上
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL||head->next==NULL)return head;
    struct ListNode *p=head,*q=head->next;
    while(q)
    {
        struct ListNode* temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    head->next=NULL;
    return p;
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

    p=reverseList(head->next);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
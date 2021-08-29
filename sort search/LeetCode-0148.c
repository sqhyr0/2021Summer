/*
对链表进行排序
自上而下归并排序，时间复杂度为O(nlogn)，空间复杂度为O(logn)
对于每个传入函数的链表
当其为空或仅有一个节点时，返回
使用快慢指针法找出这段链表的中部
使用指针L2标记slow指针的后继，使用指针L1指向head
slow->next=NULL，将这段链表一分为二,分别传入下一次函数调用
L1，L2接收到返回的指针后，随即被传入有序链表的合并函数中，进行链表的合并操作
这样，原始链表转化成了有序链表
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p=l1,*q=l2,*l=L;
    while(p&&q)
    {
        if(p->val<q->val){
            l->next=p;
            p=p->next;
        }
        else
        {
            l->next=q;
            q=q->next;
        } 
        l=l->next;

    }
    if(p)l->next=p;
    else l->next=q;
    return L->next;
}
struct ListNode* sortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* slow=head,* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    struct ListNode* L1=head,*L2=slow->next;
    slow->next=NULL;
    L1=sortList(L1);
    L2=sortList(L2);
    head=mergeTwoLists(L1,L2);
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
    p=sortList(head->next);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
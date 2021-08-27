/*
分隔链表
双指针法，时间复杂度为O(n)，空间复杂度为O(1)
申请一个新节点L，其尾指针指向头节点，便于对头节点进行操作
设置一个指针low，从L往后依次遍历，找到第一个大于x的节点的前驱，以该前驱作为low链表的尾部
指针p从low指针所指节点出发，向后遍历，每找到一个值小于x的节点，便将其添加到low链表尾部，low指针向后移动一位，同时将原链表重新连接
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* partition(struct ListNode* head, int x){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode *low=L,*p=NULL;
    while(low->next!=NULL&&low->next->val<x)low=low->next;
    p=low;
    while(p->next!=NULL)
    {
        if(p->next->val<x)
        {
            struct ListNode* temp=p->next;
            p->next=temp->next;
            temp->next=low->next;
            low->next=temp;
            low=low->next;
        }
        else p=p->next;
    }
    return L->next;
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
    int x;
    scanf("%d",&x);
    head=partition(head->next,x);
    p=head;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
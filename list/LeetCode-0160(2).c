/*
同样是令两指针走的步数相同，官方给出的是一种做加法的方法
当两指针不全为空时，任意指针指空后即转移到另一条链表的头节点上去，两指针继续向后移动
这样，必有一个时刻，两指针指向同一个节点或同时指空而退出循环
设两链表非相交节点长度分别为a与b,相交节点长度为c
依据上述方法，A指针在A链表上向后移动时，所走的步数为a+c，同理，B指针步数为b+c
转移后，A指针在B链表商向后移动时，所走步数为b，同理，B指针步数为a
则两指针所走步数皆为a+b+c，则它们必然同时指空或指向同一个节点
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL||headB==NULL)return NULL;
    struct ListNode *a=headA,*b=headB;
    while(a!=NULL||b!=NULL)
    {
        if(a==b)return a;
        if(a==NULL)a=headB;
        else a=a->next;
        if(b==NULL)b=headA;
        else b=b->next;
    }
    return NULL;
}
int main()
{
    struct ListNode* L1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* L2=(struct ListNode*)malloc(sizeof(struct ListNode));
    L1->next=NULL,L2->next=NULL;
    int temp;
    struct ListNode* p;
    p=L1;
    while(scanf("%d",&temp)!=EOF)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=temp;
        p->next=NULL;
    }
    p=L2;
    while(scanf("%d",&temp)!=EOF)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=temp;
        p->next=NULL;
    }
}
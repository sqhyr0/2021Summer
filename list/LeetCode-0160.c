/*
相交链表
使用双指针判断并返回相交的第一个节点
设链表长度分别为a与b
当两指针在同一时刻，分别从两链表头节点向后移动时
a=b，两者有相遇的可能
a≠b，两者必定无法相遇，无论链表是否相交
故，若要使两指针相遇，需设法使得两指针走过的路程相同
分别令两指针遍历一遍对应的链表，并记录链表的长度
遍历结束后，设step=a-b;
两指针重新自两链表的头节点出发，当step>0时，a链表上的指针先走step步，反之，则由b链表上的指针先走
这时，两指针向后移动并指空所需的步数是相等的，故若两链表有相交，两指针必然能在相交的第一个节点处相遇
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL||headB==NULL)return NULL;//两链表中存在空链表时必定不相交
    struct ListNode *a=headA,*b=headB;
    int lengthA=0,lengthB=0;
    while(a)
    {
        a=a->next;
        lengthA++;
    }
    while(b)
    {
        b=b->next;
        lengthB++;
    }
    int step=lengthA-lengthB;
    a=headA,b=headB;
    while(step>0)
    {
        a=a->next;
        step--;
    }
    while(step<0)
    {
        b=b->next;
        step++;
    }
    while(a!=NULL&&b!=NULL)
    {
        if(a==b)return a;
        a=a->next;
        b=b->next;
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
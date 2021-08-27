/*
合并两个有序链表
设置一个头节点L，将l1与l2的节点有序加入到其尾部
两个指针p和q分别指向l1与l2的节点，并向后扫描
在while循环中，当p与q都不为空时，即此时两链表中的元素都还没有完全加入到L中时
每次选取p与q所指节点中较小的那一个添加到L尾部，对应的指针向后移动一位
当while循环结束，即pq中存在一个为空时，剩下的那个指针所指节点以及其后所有节点必大于L中的节点，直接将其加入到L尾部
*/
#include<stdlib.h>
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
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
    return L;
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
    struct ListNode* L=mergeTwoLists(L1->next,L2->next);
    p=L;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
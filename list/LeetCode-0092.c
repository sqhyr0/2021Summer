/*
局部翻转链表
多指针+递归，时间复杂度为O(n)，空间复杂度为O(n)
设置四个哨兵指针，主指针p自链表从前往后遍历，依次将非翻转部分，待翻转部分的端点标记
再对待翻转部分递归倒置，头尾重新相连
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
void fuc(struct ListNode* Node)
{
    if(Node->next->next!=NULL)fuc(Node->next);
    Node->next->next=Node;
}
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* p=head;
    while(p->next!=NULL)p=p->next;
    fuc(head);
    head->next=NULL;
    return p;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode* p=L,*l=NULL,*r=NULL,*ll=NULL,*rr=NULL;
    int step=0;
    while(p!=NULL)
    {
        if(step==left-1)l=p;
        if(step==right)
        {
            rr=p;
            break;
        }
        p=p->next;
        step++;
    }
    ll=l->next;
    r=rr->next;
    rr->next=NULL;
    l->next=reverseList(ll);
    ll->next=r;
    return L->next;

}
int main()
{
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    int temp;
    struct ListNode* p=head;
    int length=0;
    while(scanf("%d",&temp)!=EOF)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=temp;
        p->next=NULL;
        length++;
    }
    struct ListNode *left=head,*right=head;
    int x;
    scanf("%d",&x);
    while(x--)left=left->next;
    scanf("%d",&x);
    while(length-x)right=right->next;
    head=reverseBetween(head->next,left,right);
    p=head;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
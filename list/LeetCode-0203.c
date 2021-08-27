//删去指定元素值的节点
//迭代即可，主指针向后遍历，副指针紧随其后，主指针遇到待删除节点时，副指针所指节点的next与主指针所指节点的next相连
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL)return NULL;
    //此处申请一个新节点是为了给指针一个挪移的空间，避免出现首节点无法删去的情况
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode *p=L,*q=head;
    while(q)
    {
        if(q->val==val)
            p->next=q->next;
        else 
            p=p->next;
        q=q->next;
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
    int val;
    scanf("%d",&val);
    head=removeElements(head->next,val);
    p=head;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
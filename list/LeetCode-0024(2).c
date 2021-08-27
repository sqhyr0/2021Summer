/*
两两交换链表中的节点
迭代法，时间复杂度为O(n),空间复杂度为O(1)
为对链表的头节点进行操作，需要额外申请一个新节点L，并令其尾指针指向头节点
设置一个指针p，自L开始，向后遍历，每次将p后的两个节点互换位置
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode *p=L;
    while(p->next!=NULL&&p->next->next!=NULL)
    {
        struct ListNode* temp=p->next;
        p->next=temp->next;
        temp->next=p->next->next;
        p->next->next=temp;
        p=temp;
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
    p=swapPairs(head->next);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }

}
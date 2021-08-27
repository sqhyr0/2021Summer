/*
两两交换链表中的节点
递归法，时间复杂度为O(n),空间复杂度为O(n)
递归函数中的形参每次只有一个节点，设为head
则每次递归时，链表的组成为：head,head->next，以及已经由递归而交换好的片段
故每轮递归中仅需交换head与head->next，并将新的头节点返回
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
    struct ListNode* temp=head->next;
    head->next=swapPairs(temp->next);
    temp->next=head;
    return temp;
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
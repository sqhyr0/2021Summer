/*
返回链表的中间节点
快慢指针法，时间复杂度为O(n)空间复杂度是O(1)
快慢指针从头节点出发，同时向后移动
快指针一次移动两步，慢指针一次移动一步
当快指针走到链表尾部时，慢指针刚好走到链表中间
需要注意的是，当链表长度为奇数时，快指针在倒数第二个节点处停止，慢指针刚好指向唯一的中间节点
当链表长度为偶数时，快指针在尾节点处停止，慢指针指向第一个中间节点，而题目要求的是返回第二个中间节点
故在返回时需进行判断快指针所指节点是否时尾节点,并依此返回慢指针所指节点，或它的后继
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p=head,*q=head;
    while(q->next!=NULL&&q->next->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
    }
    return q->next==NULL?p:p->next;
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
    p=middleNode(head->next);
    printf("%d",p->val);
}
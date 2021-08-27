/*
翻转链表，递归法
递归函数先将待操作节点圈定在链表的倒数第二个节点，依次进行反转尾指针操作
需要注意的是，最后传递给主函数的指针应指向原链表的最后一个节点
为避免生成环，在传递指针给主函数时，要先将原链表中的头节点的尾指针指空
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

    p=reverseList(head->next);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
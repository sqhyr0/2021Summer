/*
删除倒数第n个节点
双指针法，时间复杂度为O(n)，空间复杂度为O(1)
设置两个指针，它们相距n个节点，当前一个指针指向链表中最后一个元素时，后一个指针指向待删除节点的前驱
前一个指针先出发，从L开始走n步，随后后一个指针出发，两者同时向后移动
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
//# 1 2 3 4 5
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode* first=L,* second=L;
    int i=0;
    while(i!=n){
        first=first->next;
        i++;
    }
    while(first->next!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    second->next=second->next->next;
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
    int n;
    scanf("%d",&n);
    p=removeNthFromEnd(head->next,n);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
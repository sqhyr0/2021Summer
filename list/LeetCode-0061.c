/*
旋转链表
双指针法，时间复杂度为O(n)，空间复杂度为O(1)
设置两个指针first和second,初始时两指针皆指向head
first首先出发，向后移动，直到尾节点停止，同时记录下所走的长度，长度加1即为链表长度
利用first将首尾相连，形成一个环
k对length取模得到实际向右移动的次数
带环链表元素向右移动，实际上是头节点向右移动，
second指针出发，向后扫描length-(k%length)-1步，走到新头节点的前驱，记录新的头节点，并断开链表
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL)return head;
    struct ListNode *first=head,*second=head;
    int length=1;
    while(first->next!=NULL)
    {
        first=first->next;
        length++;
    }
    first->next=head;
    k%=length;
    while(length-k>1)
    {
        second=second->next;
        length--;
    }
    first=second->next;
    second->next=NULL;
    return first;
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
    int k;
    scanf("%d",&k);
    head=rotateRight(head->next,k);
    p=head;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
/*
删除链表中倒数第n个节点
使用递归法，时间复杂度和空间复杂度都为O(n)
先递归直达链表的尾部，再依次退出进程，设置一个变量i=0，每退出一次，i+1并将值传递回自身
当i==n时，进程刚好抵达待删除节点的前驱，将前驱与其后继相连，返回-1表示删除完毕
为避免对头节点进行复杂的判断，额外申请一个新节点，将其尾指针指向头节点，并将这个新节点作为传入递归函数的节点
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

int fuc(struct ListNode* head,int n,int i)
{
    if(head->next!=NULL)i=fuc(head->next,n,i);
    if(i==-1)return -1;
    if(i!=n)return i+1;
    else head->next=head->next->next;
    return -1;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    fuc(L,n,0);
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
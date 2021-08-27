/*
回文链表
递归法，时间复杂度为O(n)，空间复杂度为O(n)
形参有三个：
head与tail表示当前待检测部分的首尾节点，待检测部分每次递归回返后会缩小
flag用来标志当前是否出现不满足回文的情况
难点主要在于，head与tail在递归中行进的方向刚好是相反的
head向后移动，tail向前移动
为此，设置函数返回值为head->next，递归时传入的head不变，传入的tail每次向后移动
*/

#define bool int
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
}; 
struct ListNode* fuc(struct ListNode* head,struct ListNode* tail,int* flag)
{
    if(tail->next!=NULL)head=fuc(head,tail->next,flag);
    if(tail->val!=head->val)*flag=1;
    return head->next;
}
bool isPalindrome(struct ListNode* head){
    if(head==NULL||head->next==NULL)return 0;
    bool* flag=(int*)malloc(sizeof(int));
    *flag=0;
    fuc(head,head,flag);
    return *flag;
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
    printf("%d",isPalindrome(head->next));

}
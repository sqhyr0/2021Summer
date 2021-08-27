/*
删除链表中的重复元素Ⅱ
双指针法，时间复杂度是O(n),空间复杂度是O(1)
为能对头指针进行操作，额外申请一个新节点L，令其尾指针指向头节点，并以之作为新的头节点
主指针p自L开始向后扫描
当p的后继存在，且后继的后继同样存在时
若p的后继与后继的后继值相等，则证明p后有两个或多个待删除节点
设置变量val储存p的后继的值，q自p的后继出发，向后移动，寻找到第一个值与val不相等的节点
p的尾指针指向q
若p的后继与后继的后继值不相等，则p向后移动一次
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode* p=L,*q=NULL;
    int val;
    while(p->next!=NULL&&p->next->next!=NULL)
    {
        if(p->next->val!=p->next->next->val)p=p->next;
        else
        {
            q=p->next;
            while(q!=NULL&&q->val==p->next->val)q=q->next;
            p->next=q;
        }
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
    p=deleteDuplicates(head->next);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
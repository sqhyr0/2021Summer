/*
对链表进行插入排序
时间复杂度为O(n^2)，空间复杂度为O(1)
设置一个指针p，令其始终指向当前有序链表的尾节点
每次将p的后继与p作比较
后继为空时退出while循环，排序结束
后继不为空时，
若后继节点的值大于等于p所指节点的值，p=p->next
否则，标记后继的位置，q指针从L出发，直到q的后继节点的值大于待插入节点的值，并将该节点插入q与其后继中
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    struct ListNode *p=L->next;//p始终指向有序链表的尾节点
    struct ListNode *q=L;//q始终在有序链表上移动
    while(p->next!=NULL)
    {
        if(p->next->val>=p->val)p=p->next;
        else
        {
            struct ListNode* temp=p->next;
            p->next=temp->next;
            while(q->next!=p)
            {
                if(q->next->val<temp->val)q=q->next;
                else break;
            }
            temp->next=q->next;
            q->next=temp;
            q=L;
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

    p=insertionSortList(head->next);
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
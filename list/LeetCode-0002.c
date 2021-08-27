/*
两数相加
模拟法，时间复杂度为O(max(n,m)),空间复杂度为O(1)
两链表长度不一致时，需要进行补零操作
可能会出现需进位而后继为空的情况，故需判断并申请新节点
题目默认链表非空，故无需对此进行判断
补零时，不能在指针已指向空节点时再申请空间，而应该提前申请，否则链表将会断开
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p=l1,*q=l2;
    while(p!=NULL||q!=NULL)
    {   //错误的做法，在指针已指空时申请节点，这样，p的前驱的尾指针还是指空，链表断开
        /*if(p==NULL)
        {
            p=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->val=0;
            p->next=NULL;
        }
        if(q==NULL)
        {
            q=(struct ListNode*)malloc(sizeof(struct ListNode));
            q->val=0;
            q->next=NULL;

        }*/
        p->val+=q->val;  
        if(p->val>=10)
        {
            p->val%=10;
            if(p->next==NULL)
            {
                p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                p->next->val=0;
                p->next->next=NULL;
            }
            p->next->val++;
        }
        //正确的做法，在每次循环的末尾判断是否需要补零，并直接为尾指针申请空间，这样链表不会断开
        if(p->next==NULL&&q->next!=NULL)
        {
            p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            p->next->val=0;
            p->next->next=NULL;
        }
        else if(q->next==NULL&&p->next!=NULL)
        {
            q->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            q->next->val=0;
            q->next->next=NULL;

        }
        p=p->next;
        q=q->next;
    }
    return l1;
}
struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL||head->next==NULL)return head;
    struct ListNode *p=head,*q=head->next;
    while(q)
    {
        struct ListNode* temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    head->next=NULL;
    return p;
}
int main()
{
    struct ListNode* L1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* L2=(struct ListNode*)malloc(sizeof(struct ListNode));
    L1->next=NULL,L2->next=NULL;
    int temp;
    struct ListNode* p;
    p=L1;
    while(scanf("%d",&temp)!=EOF)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=temp;
        p->next=NULL;
    }
    p=L2;
    while(scanf("%d",&temp)!=EOF)
    {
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->val=temp;
        p->next=NULL;
    }
    L1->next=reverseList(L1->next);
    L2->next=reverseList(L2->next);
    struct ListNode* L=addTwoNumbers(L1->next,L2->next);
    L=reverseList(L);
    p=L;
    while(p)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
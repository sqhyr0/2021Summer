#define bool int
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
/*bool hasCycle(struct ListNode *head) {//此方法利用了所给数据上的缺陷，与作弊无异，故舍去
    int max=10001;//题设中最大的节点数为10000，故设一个大于10000的值，令指针从头开始遍历，若遍历次数能超过10000，即一定有环
    int i=0;
    struct ListNode* p=head;
    while(p)
    {
        if(i>=max)return 1;
        p=p->next;
        i++;
    }
    return 0;
}*/
/*
使用快慢指针判定链表中是否存在环结构
设置两个指针，一快一慢，每次分别在链表上向后移动两个节点和一个节点
当快指针移动到链表尾部时退出循环，证明链表中无环
循环时，若慢指针追上了快指针，即两者指向同一个节点，则证明链表中有环结构
快指针的步数设置为2是因为超过2时无法保证有环链表中慢指针一定能与快指针相遇(快指针在遍历时可能会由于步数较大而跳过慢指针的位置)
*/
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast,*slow;
    fast=slow=head;
    while(fast->next!=NULL)
    {
        
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)return 1;
    }
    return 0;
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
    //p->next=head->next;
    printf("%d",hasCycle(head->next));
}

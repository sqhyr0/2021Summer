//条件特殊，未在本地测试,仅贴出通过测试的函数
/*
删除链表中指定的节点
与一般的常规题目不同，传入参数中没有链表的头节点等信息，只有待删除节点的地址
这使得在操作时，对于链表的具体情况是不可知的
在不知道链表头节点的情况下，我们几乎不能将待删除节点的前驱与其后继相连
而题目中未要求在原地删除节点，也就是说，只要链表中待删除节点的值不在是原值即可
于是，可用待删除节点的后继的值直接将待删除节点的值覆盖，随后直接将后继删除
时间复杂度是O(1)，空间复杂度是O(1)
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    node->val=node->next->val;
    node->next=node->next->next;
}
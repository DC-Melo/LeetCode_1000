/* 两两交换链表中的节点(swap-nodes-in-pairs) */
/* Given a linked list, swap every two adjacent nodes and return its head. */
/* You may not modify the values in the list’s nodes. Only nodes itself may be changed. */
/* Example 1: */
/* 在这里插入图片描述 */
/* Input: head = [1,2,3,4] */
/* Output: [2,1,4,3] */
/* Definition for singly-linked list. */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *swapPairs(ListNode* head) 
    {
        /* ListNode **pp = &head, *a, *b; */
        ListNode **pp = &head;
        ListNode  *a;
        ListNode  *b;
        while ((a = *pp) && (b = a->next)) 
        {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};
int main(){

    ListNode *head,*last,*pcur;
    head = new ListNode(0); //添加链表头
    last = head;  
    int j;
    cout << "input the link node:";
    while((scanf("%d", &j)) != EOF){
        pcur = new ListNode(j);
        last->next = pcur;
        last = pcur;
    }
    head=head->next;
    Solution sln;
    head=sln.swapPairs(head);
    cout << "the return list node " << endl;
    pcur=head;
    while (pcur) {
        printf("-> %d ", pcur->val);
        pcur = pcur->next;
    }
    printf("\n");

}

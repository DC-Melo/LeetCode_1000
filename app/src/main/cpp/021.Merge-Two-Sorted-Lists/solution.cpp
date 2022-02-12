
/* 合并两个有序链表。 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = new ListNode(0);
        ListNode *point = head;
        while(l1 && l2)
        {
            if(l1->val < l2-> val)
            {
                point->next = l1;
                l1 = l1->next;
            }
            else
            {
                point->next = l2;
                l2 = l2->next;
            }
            point = point->next;
        }
        if(!l1)
            point->next = l2;
        else
            point->next = l1;
        return head->next;
    }
};
int main(){
    int i;
    ListNode *head1,*last1,*head2,*last2,*pcur;
    head1 = new ListNode(0); //添加链表头
    last1 = head1;  
    cout << "input the link node 1:";
    while((scanf("%d", &i)) != EOF){
        pcur = new ListNode(i);
        last1->next = pcur;
        last1 = pcur;
    }
    head1 = head1->next;//删除链表头
    cout << "you input node 1:";
    pcur = head1;
    while (pcur) {
        printf("-> %d ", pcur->val);
        pcur = pcur->next;
    }
    printf("\n");
    head2 = new ListNode(0); //添加链表头
    last2 = head2;  
    cout << "input the link node 2:";
    while((scanf("%d", &i)) != EOF){
        pcur = new ListNode(i);
        last2->next = pcur;
        last2 = pcur;
    }
    head2 = head2->next;//删除链表头
    cout << "you input node 2:";
    pcur = head2;
    while (pcur) {
        printf("-> %d ", pcur->val);
        pcur = pcur->next;
    }
    printf("\n");

    Solution sln;
    ListNode *headreturn;
    headreturn=sln.mergeTwoLists(head1, head2);
    cout << "return List node:";
    pcur = headreturn;
    while (pcur) {
        printf("-> %d ", pcur->val);
        pcur = pcur->next;
    }
    printf("\n");
}

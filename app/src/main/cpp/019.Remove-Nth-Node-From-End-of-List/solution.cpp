/* Given a linked list, remove the n-th node from the end of list and return its head. */
/* Example: */
/* Given linked list: 1->2->3->4->5, and n = 2. */
/* After removing the second node from the end, the linked list becomes 1->2->3->5. */
/* Note: */
/* Given n will always be valid. */
/* Follow up: */
/* Could you do this in one pass? */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode *tempHead = new ListNode(0);
        tempHead->next = head;
        ListNode *first = tempHead, *second = tempHead;
        
        for(int i = 0; i < n+1; i++)
            first = first -> next;

        while(first) 
        {
            first = first -> next;
            second = second -> next;
        }
        
        second->next = second->next->next;
        return tempHead->next;
    }
};
int main(){
/* Given linked list: 1->2->3->4->5, and n = 2. */
    Solution sln;
    int data;	//插入链表的数据
    int nth;
    ListNode *head = new ListNode(-1);
    ListNode* pcur=head; //不破坏头指针
    while(1)
    {
        cout << "input ListNode data:";
        cin >> data;
        if(data == -1)	//插入-1时结束链表构造
        {
        break;
        }
        ListNode* node=new ListNode(data);
        pcur->next=node;
        pcur=node;

    }
    cout<<"输入链表如下：";
    pcur=head;
    while(pcur!=NULL)
    {
        cout<<pcur->val<<" -> ";
        pcur=pcur->next;
    }
    cout << "removeNthFromEnd N:";
    cin >> nth;

    head = sln.removeNthFromEnd(head,nth);
    pcur=head;
    while(pcur!=NULL)
    {
        cout<<pcur->val<<" -> ";
        pcur=pcur->next;
    }
    cout<<"\n";
    cout<<"\n";
    return 0;
}

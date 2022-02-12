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
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        if( head==NULL || k==1 ) 
            return head;
        int sum=0;
        ListNode *preheader = new ListNode(0);
        preheader->next = head;
        ListNode *current = preheader, *forward, *precede = preheader;
        while(current = current->next) 
            sum++;
        while(sum>=k) 
        {
            current = precede->next;
            forward = current->next;
            for(int i=1;i<k;++i) 
            {
                current->next=forward->next;
                forward->next=precede->next;
                precede->next=forward;
                forward=current->next;
            }
            precede = current;
            sum-=k;
        }
        return preheader->next;
    }
};
int main(){
    Solution sln;
    ListNode *head,*last,*pcur;
    head = new ListNode(0); //添加链表头
    last = head;  
    int i;
    cout << "input the link node ctrl+D as end:";
    while((scanf("%d", &i)) != EOF){
        pcur = new ListNode(i);
        last->next = pcur;
        last = pcur;
    }
    head=head->next;//remove the dummy node

    int k;
    cout << "input the reverse K:";
    cin >> k;
    head=sln.reverseKGroup(head,k);

}

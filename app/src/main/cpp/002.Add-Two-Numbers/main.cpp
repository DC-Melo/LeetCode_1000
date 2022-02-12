#include <iostream>
#include "solution.h"

int main()
{

    ListNode *l1   = new ListNode(9);
    l1->next       = new ListNode(9);
    l1->next->next = new ListNode(9);

    ListNode *l2   = new ListNode(9);
    l2->next       = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    Solution sln;
    ListNode *result = sln.addTwoNumbers(l1,l2);
    do {
        std::cout << result->value << std::endl;
        result = result->next;
    } while (result != NULL);

}


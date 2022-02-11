#include "solution.h"
ListNode *Solution::addTwoNumbers(ListNode *l1,ListNode *l2){
    int carry=0;
    ListNode *result = new ListNode(0);
    ListNode *nodei = result;

    int val1;
    int val2;

    while(l1 != NULL || l2 != NULL){
        if (l1 != NULL) val1 = l1->value;
        else val1 = 0;
        if (l2 != NULL) val2 = l2->value;
        else val2 = 0;

        nodei->next = new ListNode((val1+val2+carry)%10);
        carry = (val1+val2+carry)/10;

        nodei = nodei->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    if (carry != 0) {
        nodei->next = new ListNode(carry);
    }
    return result->next;
}

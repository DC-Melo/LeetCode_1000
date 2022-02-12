#pragma once
#include <iostream>
struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x):value(x),next(NULL) {}
};
class Solution
{
public:
    Solution() {}
    ~Solution() {}
    ListNode *addTwoNumbers(ListNode *l1,ListNode *l2);
private:

};


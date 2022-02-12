#pragma once
#include <iostream>
#include "vector"
#include "math.h"
#include <unordered_map>

using namespace std;
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
    vector<int> twoSum(vector<int> &numbers, int target);
    ListNode *addTwoNumbers(ListNode *l1,ListNode *l2);
    int lengthOfLongestSubstring(string s);
private:

};


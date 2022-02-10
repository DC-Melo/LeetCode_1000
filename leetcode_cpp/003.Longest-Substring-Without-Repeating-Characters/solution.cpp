/* Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1. */
/* 【解题思路】用一个hash table保存每个字符上一次出现过的位置。从前往后扫描，假如发现字符上次出现过，就把当前子串的起始位置start移动到上次出现过的位置之后——这是为了保证从start到i的当前子串中没有任何重复字符。同时，由于start移动，当前子串的内容改变，start移动过程中经历的字符都要剔除。 */

#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0, right=0;
        int maxLength=0, length=0;
        vector<bool> flag(255,false);
        for(;right<s.size();right++)
        {
            if(flag[s[right]] == true)
            {
                for(;s[left] != s[right];left++)
                {
                    flag[s[left]] = false;
                    length --;
                }
                left++;
            }
            else
            {
                flag[s[right]] = true;
                length++;
                if(length > maxLength) 
                    maxLength = length;
            }
        }
        return maxLength;
    }
};

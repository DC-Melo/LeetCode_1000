/* Write a function to find the longest common prefix string amongst an array of strings. */
/* If there is no common prefix, return an empty string "". */
/* Example 1: */
/* Input: ["flower","flow","flight"] */
/* Output: "fl" */
/* Example 2: */
/* Input: ["dog","racecar","car"] */
/* Output: "" */
/* Explanation: There is no common prefix among the input strings. */
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
        if( strs.size() == 0)
            return "";
        string prefix = strs[0];
        for(int i = 0;i<strs.size();i++)
        {
            if(prefix.size() == 0 || strs[i].size() == 0)
                return "";
            int j = 0;
            while(prefix[j] == strs[i][j])
            {
                j++;
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};
int main(){
    Solution sln;
    vector<string> strs={"flower","flow","flight"};
    cout << sln.longestCommonPrefix(strs) << endl;
    return 0;
}

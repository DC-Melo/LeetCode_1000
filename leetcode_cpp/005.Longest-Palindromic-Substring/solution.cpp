/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000. */

/* Example 1: */

/* Input: "babad" */
/* Output: "bab" */
/* Note: "aba" is also a valid answer. */
/* Example 2: */

/* Input: "cbbd" */
/* Output: "bb" */
/* [解法]从中间像两边分别逐个扩展 */
#include <iostream>
using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int position, maxLength=0, length=0;
        for(int i=0;i<s.size();i++)
        {
            length = 1;
            for(int j=1;i+j<s.size()&&i-j>=0;j++)
            {
                if(s[i-j] == s[i+j])
                    length += 2;
                else
                    break;
            }
            if(length > maxLength)
            {
                maxLength = length;
                position = i-length/2;
            }
        }
        
        for(int i=0;i+1<s.size();i++)
        {
            length = 0;
            for(int j=0;i+1+j<s.size()&&i-j>=0;j++)
            {
                if(s[i-j] == s[i+1+j])
                    length += 2;
                else
                    break;
            }
            if(length > maxLength)
            {
                maxLength = length;
                position = i-length/2+1;
            }
        }
        return s.substr(position,maxLength);
    }
};

int main(){
string str="aaaaaaaaaalevelbbbbbbbbb";
Solution sln;
cout << str << sln.longestPalindrome(str) << endl;

}

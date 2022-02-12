/* Given a string containing just the characters ‘(’, ‘)’, ‘{’, ‘}’, ‘[’ and ‘]’, determine if the input string is valid. */
/* An input string is valid if: */
/* Open brackets must be closed by the same type of brackets. */
/* Open brackets must be closed in the correct order. */
/* Note that an empty string is also considered valid. */
/* Example 1: */
/* Input: "()" */
/* Output: true */
/* 1 */
/* 2 */
/* Example 2: */
/* Input: "()[]{}" */
/* Output: true */
/* 1 */
/* 2 */
/* Example 3: */
/* Input: "(]" */
/* Output: false */
/* 1 */
/* 2 */
/* Example 4: */
/* Input: "([)]" */
/* Output: false */
/* 1 */
/* 2 */
/* Example 5: */
/* Input: "{[]}" */
/* Output: true */
#include <iostream>
/* #include <vector> */
#include <string>
#include <stack>
/* #include <algorithm> */
using namespace std;
class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '(': stk.push(')');break;
                case '[': stk.push(']');break;
                case '{': stk.push('}');break;
                case ')': 
                case ']':
                case '}':
                    if(stk.empty() || stk.top() != s[i]) 
                        return false;
                    else
                        stk.pop();
                    break;
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};
int main(){
    Solution sln;
    int a = 0x31;
    string input="adsfsad(asdfasf ( adfsafa[adfsafda{asdfsa} adfsaf] adfa ) adfasfd)[adfsa]";
    //将符号放进堆栈，遇到反符号就弹出堆栈，并进行比较
    cout << sln.isValid(input)<<endl;
    return 0;

}

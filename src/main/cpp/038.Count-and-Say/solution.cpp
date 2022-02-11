/* The count-and-say sequence is the sequence of integers with the first five terms as following: */
/* 1.     1 */
/* 2.     11 */
/* 3.     21 */
/* 4.     1211 */
/* 5.     111221 */
/* 1 is read off as "one 1" or 11. */
/* 11 is read off as "two 1s" or 21. */
/* 21 is read off as "one 2, then one 1" or 1211. */
/* Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. */
/* Note: Each term of the sequence of integers will be represented as a string. */
/* Example 1: */
/* Input: 1 */
/* Output: "1" */
/* Example 2: */
/* Input: 4 */
/* Output: "1211" */
#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string revolution(string s)
    {
        string ret;
        /* char pre =s[0]; */ 
        int i,j;
        int count = 1;
        for(i = 1, j=0; i < s.size(); i ++)
        {
            if(s[i]==s[j])
            {
                count ++;
            }
            else
            {
                char tmp =  count+'0';
                ret = ret + tmp + s[j];
                /* s[j] = s[i]; */
                j=i;
                count = 1;
            }
        }
        char tmp =  count+'0';
        ret = ret + tmp + s[j];
        return   ret;
    }
    string countAndSay(int n) 
    {
        string ret = "1";
        int j = 1;
        while( j< n)
        {
            ret=revolution(ret);
            j++;
        }
        return ret;
    }
};
int main(){
    Solution sln;
    string ret4=sln.countAndSay(4);
    string ret5=sln.countAndSay(5);
    string ret6=sln.countAndSay(6);
    cout << "countAndSay(4)"<< ret4 << endl;
    cout << "countAndSay(5)"<< ret5 << endl;
    cout << "countAndSay(6)"<< ret6 << endl;

}

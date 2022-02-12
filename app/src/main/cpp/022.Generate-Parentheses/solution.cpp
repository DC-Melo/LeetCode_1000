/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */
/* For example, given n = 3, a solution set is: */
/* "((()))", "(()())", "(())()", "()(())", "()()()" */
#include <vector>
#include <iostream>
using namespace std;
class Solution 
{
public:
    void generate(vector<string> &strList, string str, int k, int length)
    {
        if(str.size() == length)
        {
            if(k==0) strList.push_back(str);
            return;
        }
        if(k>0)
        {
            generate(strList, str+')', k-1, length);
        }
        generate(strList, str+'(', k+1, length);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> strList;
        string str;
        generate(strList, str, 0, n*2);
        return strList;
    }
};
int main(){
    Solution sln;
    int n=3;
    vector<string> str;
    str=sln.generateParenthesis(n);
    cout << "the output is:";
    for(int i=0;i<str.size();i++) {
        cout << str[i]<< ", ";
    }
    cout << endl;
}

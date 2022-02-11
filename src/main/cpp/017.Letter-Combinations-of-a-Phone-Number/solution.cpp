/* 题目： */
/* Given a digit string, return all possible letter combinations that the number could represent. */
/* A mapping of digit to letters (just like on the telephone buttons) is given below. */
/* 这里写图片描述 */
/* Input:Digit string “23” */
/* Output: [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”]. */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if(digits == "")
            return result;
            
        result.push_back("");
        
        vector<string> dict(10);
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        
        for(int i = 0; i < digits.size(); i ++)
        {
            int size = result.size();
            for(int j = 0; j < size; j ++)
            {
                string current = result[0];
                result.erase(result.begin());
                for(int k = 0; k < dict[digits[i]-'0'].size(); k ++)
                    result.push_back(current + dict[digits[i]-'0'][k]);
            }
        }
        return result;
    }
};
int main(){
    Solution sln;
    string digits ="23";
    vector<string> result;
    result=sln.letterCombinations(digits);
    /* for (vector<string>::iterator itee = result.begin(); itee != result.end(); itee++){ */
    /*          cout << *itee << endl; */
    /* } */
}

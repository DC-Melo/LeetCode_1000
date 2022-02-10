#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<string> anagrams(vector<string> &strs) 
    {
        string s;
        map<string, int> anagram;
        vector<string> result;
        for (int i = 0; i < strs.size(); ++i) 
        {
            s = strs[i];
            sort(s.begin(), s.end());
            /* 用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器 */
            if (anagram.find(s) == anagram.end()) 
            {
                anagram[s] = i;
            } 
            else 
            {
                if (anagram[s] >= 0) 
                {
                    result.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;        
    }
};
int main()
{        
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> res = sol.anagrams(strs);
    return 0;
}

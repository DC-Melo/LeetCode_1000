// 函数用于判断needle是否为haystack的子串，如果是，则返回needle在haystack中首次出现的索引。如果不存在，返回-1。
#include <string>
#include <iostream>
using namespace std;
// class Solution 
// {
// public:
//     int strStr(string haystack, string needle) 
//     {
//         if(needle.size() == 0) return 0;
//         for(int i=0;i<haystack.size();i++)
//         {
//             int j = 0;
//             for(j;j<needle.size();j++)
//             {
//                 if(haystack[i+j] != needle[j])
//                     break;
//             }
//             if(j == needle.size())
//                 return i;
//         }
//         return -1;
//     }
// };

class Solution {
public: 
    int strStr(string haystack, string needle) 
    {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        for (int i = 0; i < m - n + 1; i++) 
        {
            int j = 0;
            for (; j < n; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n) return i;
        }
        return -1;
    }
};
int main(){
    Solution sln;
    string a = "i f**k you";
    string b ="f**k";
    int ret =sln.strStr(a,b);
    cout << "at position:" << ret<< endl;

}

#include "solution.h"
/* 动态规划 */
string Solution::longestPalindrome(string s)
{
    if (s.empty()) return "";
    int len = s.size();
    if (len == 1)return s;
    int longest = 1;
    int start=0;
    vector<vector<bool> > dp(len,vector<bool>(len));
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = true; // 对角线单字符为回文
        if(i<len-1 && s[i] == s[i + 1]) // 两个字符为回文
        {
            dp[i][i + 1] = true;
            start=i;
            longest=2;
        }
    }
    for (int l = 3; l <= len; l++)//子串长度
    {
        for (int i = 0; i+l-1 < len; i++)//枚举子串的起始点
        {
            int j=l+i-1;//终点
            if (s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                start=i;
                longest = l;
            }
        }
    }
    return s.substr(start,longest);
}

/* he string “PAYPALISHIRING” is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility) */
/* 将字符串 “PAYPALISHIRING” 以Z字形排列成给定的行数： */

/* P   A   H   N */
/* A P L S I I G */
/* Y   I   R */


#include <iostream>
using namespace std;
class Solution 
{
public:
    string convert(string s, int nRows) 
    {
        int strLength = s.length();
        int flag = 0;
        /* string result(s); */
        string result(strLength,'*');

        if(nRows == 1)
            return result;

        for(int  i = 0;i < strLength ; i += 2*nRows-2)
        {
            result[flag] = s[i];
            flag++;
        }

        for (int i = 1; i < nRows -1  ; i ++ )
        {
            int flagM = flag;
            int flagN = flag+1;
            for(int m = i; m < strLength; m += 2*nRows-2)
            {
                result[flagM] = s[m];
                flagM+=2;
                flag++;
            }
            for(int n = i + 2*(nRows - i - 1);n < strLength;n += 2*nRows-2)
            {
                result[flagN] = s[n];
                flagN+=2;
                flag++;
            }
        }

        for(int  i = nRows - 1;i < strLength ; i += 2*nRows-2)
        {
            result[flag] = s[i];
            flag++;
        }
        return result;
    }
};

int main(){
    Solution sln;
    string str="PAYPALISHIRING";
    cout << str<< "\n"<<sln.convert(str,4)<<endl;
}

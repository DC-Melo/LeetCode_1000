#include <iostream>
using namespace std;
class Solution 
{
public:
    int jump(int A[], int n) 
    {
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < n; i ++)
        {
            if(curRch < i)
            {
                ret ++;
                curRch = curMax;
            }
            curMax = max(curMax, A[i]+i);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
    Solution sln;
    int input[]={2,3,1,1,4 };
    int output=sln.jump(input,5);
    std::cout << "output:" << output << std::endl;
    return 0;
}

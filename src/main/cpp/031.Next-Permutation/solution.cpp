/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. */
/* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). */
/* The replacement must be in-place, do not allocate extra memory. */
/* Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column. */
/* 1,2,3 → 1,3,2 */
/* 3,2,1 → 1,2,3 */
/* 1,1,5 → 1,5,1 */
#include <vector>
using namespace std;
class Solution 
{
public:
    void nextPermutation(vector<int> &num) 
    {
        if(num.size() < 2) return;
        int curMax = num[num.size() - 1];
        for(int i = num.size() - 1; i >= 0;i--)
        {
            if(num[i] < curMax)
            {
                int tmp = num[i];
                int j = 0;
                for(j = i + 1; j < num.size();j++)
                {
                    if(tmp < num[j])
                    {
                        num[i] = num[j];
                        num[j] = tmp;
                        return;
                    }
                }
                if(j == num.size())
                {
                    num[j - 1] = tmp;
                    return;
                }
            }
            else
            {
                curMax = num[i];
                for(int j = i + 1; j < num.size();j++)
                    num[j - 1] = num[j];
                num[num.size() - 1] = curMax;
            }
        }
    }
};
int main(){
    Solution sln;

}

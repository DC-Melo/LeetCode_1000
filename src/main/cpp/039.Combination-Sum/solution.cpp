/* Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order. */
/* The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different. */
/* It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input. */
/* Example 1: */
/* Input: candidates = [2,3,6,7], target = 7 */
/* Output: [[2,2,3],[7]] */
/* Explanation: */
/* 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times. */
/* 7 is a candidate, and 7 = 7. */
/* These are the only two combinations. */
/* Example 2: */
/* Input: candidates = [2,3,5], target = 8 */
/* Output: [[2,2,2,2],[2,3,3],[3,5]] */
/* Example 3: */
/* Input: candidates = [2], target = 1 */
/* Output: [] */
/* Example 4: */
/* Input: candidates = [1], target = 1 */
/* Output: [[1]] */
/* Example 5: */
/* Input: candidates = [1], target = 2 */
/* Output: [[1,1]] */
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        vector<int> vecTmp;
 
        m_vecRet.clear();
        sort(candidates.begin(), candidates.end());
        combination(candidates, 0, vecTmp, target);
 
        return m_vecRet;
    }
 
private:
    void combination(const vector<int> &candidates, size_t idx, vector<int> &curr, int target)
    {
        if (target == 0)
        {
            m_vecRet.push_back(curr);
        }
        else
        {
            for (size_t i = idx; i < candidates.size(); ++i)
            {
                if (target >= candidates[i])
                {
                    curr.push_back(candidates[i]);
                    combination(candidates, i, curr, target - candidates[i]);
                    curr.pop_back();
                }
            }
        }
    }
 
private:
    vector<vector<int> > m_vecRet;
};
int main(){
    Solution sln;
    vector<int> candidates = {2,6,3,7};
    int target = 7;
    vector<vector<int>> ret=sln.combinationSum(candidates,target);
/* Input: candidates = [2,3,6,7], target = 7 */

}

/* Given an array nums of n integers, are three elements a, b, c in nums such that a+b+c=0? Find all unique triplets in the array which gives the sum of zero. */
/* Note： */
/* The solution set must not contain duplicate triplets. */
/* Example： */
/* > Given array nums = [-1, 0, 1, 2, -1, -4], */
/* A solution set is: */
/* [[-1, 0, 1],[-1, -1, 2]] */
/* 使用三重循环 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;

        sort(num.begin(),num.end());

        for( int pos1 = 0;pos1<num.size();pos1++)
        {
            for(int pos2 = pos1 + 1, pos3 = num.size() - 1; pos2 < pos3;)
            {
                int sum = num[pos1] + num[pos2] + num[pos3];
                if(sum == 0)
                {
                        vector<int> tempResult;
                        tempResult.push_back(num[pos1]);
                        tempResult.push_back(num[pos2]);
                        tempResult.push_back(num[pos3]);
                        result.push_back(tempResult);

                        while( pos2+1 < pos3 && num[pos2+1] == num[pos2])
                            pos2++;
                        pos2++;
                        
                        while( pos3-1 > pos2 && num[pos3-1] == num[pos3])
                            pos3--;
                        pos3--;
                }
                else if(sum < 0)
                    pos2++;
                else
                    pos3--;
            }
            while( pos1+1 < num.size() && num[pos1+1] == num[pos1])
                pos1++;
        }
        return result;
    }
};
int main(){
    vector<int> nums={-1, 0, 1, 2, -1, -4};
    Solution sln;
    vector<vector<int> > rt;
    rt=sln.threeSum(nums);
    for(int i = 0; i < rt.size(); i++){
       for(int j = 0; j < rt[i].size(); j++){
          cout << rt[i][j] << " ";
       }
       cout << endl;
    }
}

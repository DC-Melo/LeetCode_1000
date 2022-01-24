#include "solution.h"
std::vector<int> Solution::twoSum(vector<int> &nums,int target){
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j<nums.size() ; ++j) {
            if(nums[i]+nums[j]==target){
                std::cout << "i="<<i<<" j="<<j << std::endl;
                ret.push_back(i);
                ret.push_back(j);
            }
        }
    }
    return ret;
}

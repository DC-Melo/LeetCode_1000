#include "solution.h"
std::vector<int> Solution::twoSum(vector<int> &nums,int target){
    unordered_map<int, int> dataHash;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        int findVal = target - nums[i];
        if (dataHash.find(findVal)!=dataHash.end()){
            result.push_back(dataHash[findVal]);
            result.push_back(i);
            return result;
        }else{
            dataHash[nums[i]]=i;
        }

    }
}

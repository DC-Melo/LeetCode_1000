#include <iostream>
#include <vector>
#include <list>	
#include <set>
#include <map>	
#include "solution.h"

int main()
{
    vector<int> nums1={1,3,5,7};
    vector<int> nums2={2,4,6,8};
    Solution sln;
    double res= sln.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}


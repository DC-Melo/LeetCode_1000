#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        int medianPos = 0;
        int p1,p2;
        for(p1=0,p2=0;p1<nums1.size() && p2<nums2.size();)
        {
            if(nums1[p1] < nums2[p2])
            {
                res.push_back(nums1[p1]);
                p1++;
            }
            else
            {
                res.push_back(nums2[p2]);
                p2++;
            }
        }
        for(;p1 < nums1.size();p1++)
            res.push_back(nums1[p1]);
        for(;p2 < nums2.size();p2++)
            res.push_back(nums2[p2]);
        medianPos = (nums1.size() + nums2.size())/2;
        if((nums1.size()+nums2.size())%2 == 0) 
            return (res[medianPos - 1] + res[medianPos]) / 2.0;
        return res[medianPos];
    }
};
int main(){
    vector<int> nums1={1,3,5,7};
    vector<int> nums2={2,4,6,8};
    Solution sln;
    double res= sln.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}

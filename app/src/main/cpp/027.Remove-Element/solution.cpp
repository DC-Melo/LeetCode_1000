/* 题目描述 */
/* Given an array nums and a value val, remove all instances of that value in-place and return the new length. */
/* Do not allocate extra space for another array, you must do this by modifying the input array in-place with O ( 1 ) O(1)O(1) extra memory. */
/* The order of elements can be changed. It doesn’t matter what you leave beyond the new length. */
/* Example 1: */
/* Given nums = [3,2,2,3], val = 3, */
/* Your function should return length = 2, with the first two elements of nums being 2. */
/* It doesn't matter what you leave beyond the returned length. */
/* Example 2: */
/* Given nums = [0,1,2,2,3,0,4,2], val = 2, */
/* Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4. */
/* Note that the order of those five elements can be arbitrary. */
/* It doesn't matter what values are set beyond the returned length. */
#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int length = 0;
        for(int i=0,j=0;j<nums.size();j++)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
                length ++;
            }
        }
        return length;
    }
};
int main(){

    int j;
    vector<int> list1;
    int val;
    cout << "input the vector<int>:";
    while((scanf("%d", &j)) != EOF){
        list1.push_back(j);
    }
    cout <<"intput the value:";
    cin >> val;
    Solution sln;
    int len=sln.removeElement(list1,val);
    cout << "removed length:" << len<< endl;
}

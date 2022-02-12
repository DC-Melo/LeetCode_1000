#include <iostream>
#include <vector>
using namespace std;
/* 删除排序数组中的重复项 II */
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int length = nums.size();
        for(int i=0,j=1;j<nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else
                length--;
        }
        return length;
    }
};
int main(){
    int j;
    vector<int> list1;
    cout << "input the vector<int>:";
    while((scanf("%d", &j)) != EOF){
        list1.push_back(j);
    }
    Solution sln;
    int len=sln.removeDuplicates(list1);
    cout << "removed length:" << len<< endl;
}

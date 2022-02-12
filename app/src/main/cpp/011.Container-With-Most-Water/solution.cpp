/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. */
/* Note: You may not slant the container and nis at least 2. */
/* The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49. */
/* 题目描述： */
/* 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 */
/* 说明：你不能倾斜容器，且 n 的值至少为 2。 */
/* 解法：左右板分别向中间移动，由于距离变短，一定要找更高的板子。 */
#include <iostream>
#include "vector"
using namespace std;
class Solution 
{
public:
    int maxArea(vector<int> &height) 
    {
        int left = 0;
        int right = height.size() -1;

        int maxArea = 0;
        while(left < right)
        {
            int area = (right - left)*min(height[left],height[right]);
            maxArea = max(maxArea,area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
int main(){
    Solution sln;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout << sln.maxArea(height) << endl;
    return 0;
}

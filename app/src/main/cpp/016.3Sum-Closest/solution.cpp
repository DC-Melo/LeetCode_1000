/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution. */
/*  For example, given array S = {-1 2 1 -4}, and target = 1. */
/*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        int closestSum = num[0]+num[1]+num[2];
        sort(num.begin(),num.end());

        for( int num1pos = 0; num1pos<num.size(); num1pos++ )
        {
            for(int num2pos=num1pos+1, num3pos=num.size()-1; num2pos < num3pos;)
            {
                int sum = num[num1pos] + num[num2pos] + num[num3pos];
                if(sum == target)
                    return target;
                
                if(abs(sum-target)<abs(closestSum-target))
                        closestSum = sum;
                
                if(sum < target)
                    num2pos++;
                else
                    num3pos--;
            }
        }
        return closestSum;
    }
};
int main(){
    Solution sln;
    vector<int> S={-1,2,1,-4};
    int target = 1;
    cout << sln.threeSumClosest(S,target)<< endl;
}

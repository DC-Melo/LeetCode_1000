#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution1 
{
public:
    int trap(int A[], int n) 
    {
        int leftMax = 0;
        int left[n]; 
        for(int i=0;i<n;i++)
        {
            left[i] = leftMax;
            if(A[i] > leftMax)
                leftMax = A[i];
        }

        int rightMax = 0;
        int right[n]; 
        for(int i=n-1;i>=0;i--)
        {
            right[i] = rightMax;
            if(A[i] > rightMax)
                rightMax = A[i];
        }

        int result = 0;
        int temp;
        for(int i=0;i<n;i++)
        {
            temp = min(left[i],right[i]);
            if(temp > A[i])
                result += temp-A[i];
        }
        return result;
    }
};
class Solution2 {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};
class Solution3 {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};
class Solution4 {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};
class Solution5 {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[st.top()] >= height[i]) {
                st.push(i++);
            } else {
                int m = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[m]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};
int main(){
    int A[]={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> B={0,10,0,20,10,0,19,30,20,10,20,10};
    Solution1 sln1;
    Solution2 sln2;
    Solution3 sln3;
    Solution4 sln4;
    Solution5 sln5;
    int ret1=sln1.trap(A,12);
    int ret2=sln2.trap(B);
    int ret3=sln3.trap(B);
    int ret4=sln4.trap(B);
    int ret5=sln5.trap(B);
    cout << "ret1:"<< ret1<< endl;
    cout << "ret2:"<< ret2<< endl;
    cout << "ret3:"<< ret3<< endl;
    cout << "ret4:"<< ret4<< endl;
    cout << "ret5:"<< ret5<< endl;
}

#include <iostream>
#include <vector>
#include <math>
using namespace std;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) 
    {
        int len = num.size();
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        gen(res, num, 0, len);
        return res;
    }
    
    bool isSwap(vector<int>& num, int s, int e) 
    {
        int i = s;
        while (num[i] != num[e] && i < e) i++;
        if (i == e) return true;
        else return false;
    }
    
    void gen(vector<vector<int> > &res, vector<int>& num, int cur, int len) 
    {
        if (cur == len) {
            res.push_back(num);
            return;
        }

        for (int i = cur; i < len; i++) {
            if (!isSwap(num, cur, i)) continue;
            swap(num[cur], num[i]);
            gen(res, num, cur+1, len);
            swap(num[cur], num[i]);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    int input[]={2,3,1,1,4 };
    int output=sln.jump(input,5);
    std::cout << "output:" << output << std::endl;
    return 0;
}

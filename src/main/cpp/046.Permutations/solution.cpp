#include<vector>
#include<algorithm>
#include<exception>
using namespace std;

class Solution 
{
public:
    vector<int> nextPermutation(vector<int> &num) 
    {
        if(num.size() < 2) 
            return num;
        int curMax = num[num.size() - 1];
        for(int i = num.size() - 1; i >= 0;i--)
        {
            if(num[i] < curMax)
            {
                int tmp = num[i];
                int j = 0;
                for(j = i + 1; j < num.size();j++)
                {
                    if(tmp < num[j])
                    {
                        num[i] = num[j];
                        num[j] = tmp;
                        return num;
                    }
                }
                if(j == num.size())
                {
                    num[j - 1] = tmp;
                    return num;
                }
            }
            else
            {
                curMax = num[i];
                for(int j = i + 1; j < num.size();j++)
                    num[j - 1] = num[j];
                num[num.size() - 1] = curMax;
            }
        }
        return num;
    }
    vector<vector<int> > permute(vector<int> &num) 
    {
        long long n = num.size();
        for(int i=n-1;i>0;i--)
            n *= i;
        vector<vector<int> > result;
        while(n--)
            result.push_back(nextPermutation(num));
        return result;
    }
};

class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level == num.size()) {res.push_back(out); return;}
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};

class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        if (num.empty()) return vector<vector<int>>(1, vector<int>());
        vector<vector<int>> res;
        int first = num[0];
        num.erase(num.begin());
        vector<vector<int>> words = permute(num);
        for (auto &a : words) {
            for (int i = 0; i <= a.size(); ++i) {
                a.insert(a.begin() + i, first);
                res.push_back(a);
                a.erase(a.begin() + i);
            }
        }
        return res;
    }
};

class Solution4 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res{{}};
        for (int a : num) {
            for (int k = res.size(); k > 0; --k) {
                vector<int> t = res.front();
                res.erase(res.begin());
                for (int i = 0; i <= t.size(); ++i) {
                    vector<int> one = t;
                    one.insert(one.begin() + i, a);
                    res.push_back(one);
                }
            }
        }
        return res;
    }
};

class Solution5 {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num.begin(), num.end())) {
            res.push_back(num);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    Solution1 sln1;
    Solution2 sln2;
    Solution3 sln3;
    Solution4 sln4;
    Solution5 sln5;
    vector<int> input={ 4, 3, 2, 1 };
    vector<vector<int>> ret=sln.permute(input);
    vector<vector<int>> ret1=sln1.permute(input);
    vector<vector<int>> ret2=sln2.permute(input);
    vector<vector<int>> ret3=sln3.permute(input);
    vector<vector<int>> ret4=sln4.permute(input);
    vector<vector<int>> ret5=sln5.permute(input);
    return 0;
}

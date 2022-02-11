#include <iostream>
#include "solution.h"

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> numbers={2, 7, 11, 15};
    int target = 18;
    vector<int> outcome = s.twoSum(numbers, target);
    for (int i = 0; i < outcome.size(); i++) {
            cout << outcome[i] << " ";
        }
        cout << endl;
    return 0;
}

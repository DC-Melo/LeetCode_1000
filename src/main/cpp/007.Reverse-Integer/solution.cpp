#include <iostream>
using namespace std;

class Solution 
{
public:
    int reverse(int x) 
    {
        int flag = x > 0? 1:-1;
        x = abs(x);

        long int result = 0;
        int digit = 0;
        while(x)
        {
            digit = x % 10;
            result = result * 10 + digit;
            x /= 10;
        }

        result *= flag;

        if(result > 2147483647 || result < -2147483648)
            return 0;

        return (int)result; 
    }
};
int main(){
    Solution sln;
    cout << sln.reverse(12345) << endl;
    cout << sln.reverse(-12345) << endl;
    return 0;
}

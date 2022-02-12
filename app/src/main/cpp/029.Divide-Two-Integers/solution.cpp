#include <iostream>
#include <limits.h>
using namespace std;

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0))? -1:1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long result = 0;
        long long tempDivisor;
        int base;
        while(dvd >= dvs)
        {
            tempDivisor = dvs;
            base = 1;
            while( (dvd>>1) >= tempDivisor )
            {
                tempDivisor <<= 1;
                base <<= 1;
            }
            dvd -= tempDivisor;
            result += base;
        }
        return sign>0? result:-result;
    }
};
int main(){
    Solution sln;
    int dividend,divisor;
    cout << "input the dividend:";
    cin >> dividend;
    cout << "input the divisor:";
    cin >> divisor;
    int ret=sln.divide(dividend,divisor);
}

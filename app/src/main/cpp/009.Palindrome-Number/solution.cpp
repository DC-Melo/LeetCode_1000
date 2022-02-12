/* Palindrome-Number */
/* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward. */

/* Follow up: Could you solve it without converting the integer to a string? */


#include <iostream>
using namespace std;
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int rev=0;
        while(x>rev)
        {
            rev = rev*10+x%10;
            x = x/10;
        }
        return (x==rev)||(x==rev/10);
    }
};
int main(){
    Solution sln;
    int a=1221;
    cout << sln.isPalindrome(a) << endl;
    return 0;
}


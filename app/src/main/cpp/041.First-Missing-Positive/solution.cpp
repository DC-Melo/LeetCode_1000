/* Given an unsorted integer array, find the first missing positive integer. */

/* For example, */
/* Given [1,2,0] return 3, */
/* and [3,4,-1,1] return 2. */

/* Your algorithm should run in O(n) time and uses constant space. */
class Solution 
{
public:
    void swap(int &a,int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int firstMissingPositive(int A[], int n) 
    {
        for(int i=0;i<n;i++)
        {
            while(A[i]!=i+1)
            {
                if(A[i]>=n||A[i]<=0||A[i]==A[A[i]-1])
                    break;
                swap(A[i],A[A[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
int main(){
    Solution sln;
    int A[]={-1,3,4,1};
/* and [3,4,-1,1] return 2. */
    int ret=sln.firstMissingPositive(A,4);
}

#include "solution.h"
vector<int> Solution::twoSum(vector<int> &numbers, int target)
{
    // Creating first child
    int n1 = fork();

    // Creating second child. First child
    // also executes this line and creates
    // grandchild.
    int n2 = fork();

    if (n1 > 0 && n2 > 0)
    {
        printf("parent\n");
        printf("%d %d \n", n1, n2);
        printf(" my id is %d \n", getpid());
        printf(" my parentid is %d \n", getppid());
    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("First child\n");
        printf("%d %d \n", n1, n2);
        printf("my id is %d  \n", getpid());
        printf(" my parentid is %d \n", getppid());
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("second child\n");
        printf("%d %d \n", n1, n2);
        printf("my id is %d  \n", getpid());
        printf(" my parentid is %d \n", getppid());
    }
    else {
        printf("third child\n");
        printf("%d %d \n", n1, n2);
        printf(" my id is %d \n", getpid());
        printf(" my parentid is %d \n", getppid());
    }
    // 使用哈希表存储数组中的数值，key为数组中的数值，value为数组中数值对应下标 
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) 
    {
        int numberToFind = target - numbers[i];

        // 查找，若找到，则返回下标
        if (hash.find(numberToFind) != hash.end()) 
        {
            result.push_back(hash[numberToFind]);
            result.push_back(i);            
            return result;
        }

        //若没有找到，则将该值加入哈希表
        hash[numbers[i]] = i;
    }



}

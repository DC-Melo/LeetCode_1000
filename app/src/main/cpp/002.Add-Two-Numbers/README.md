## LeetCode #2 - Add Two Numbers Represented By Linked Lists
September 27, 2020

Hello fellow devs 👋! It’s a brand new day and we have a brand new problem from LeetCode - Add Two Numbers

0002 - Add Two Numbers.

Problem Statement
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

Explanation: 342 + 465 = 807.

Analysis
This is nothing but a simple elementary addition problem. The only difference is that the numbers to be added are represented by linked list where each digit is represented by the nodes of that linked list.

If we see the example then we will see that the digits are in the reverse order i.e.,

First node => ones place
Second node => tens place
Third node => hundreds place
... and so on.
Thus 2 -> 4 -> 3 will actually make 342 and 5 -> 6 -> 4 will actually make 465.

We will have to return a new linked list whose nodes will represent the digits of the sum of the numbers represented by the given two linked list.

Approach
Traverse two linked lists.
In each iteration, add the numbers in the nodes of the linked lists
If the lists are unequal, then the smaller one will end before the longer. In this case, we will put only the remaining nodes of the longer list in the resultant list
If the sum of two digits is greater than 9, then we will have to find out the “carry” to be added in the next iteration.
This is nothing more than a simple addition. The only challenge here might be to avoid NullPointerException which is very common in the linked list based problems.

Time Complexity
Since we are iterating both the lists only once, the time complexity would be O(m + n). Here m and n are the numbers of nodes in the two linked lists.

Space Complexity
Since we are using extra space only for our variables, our space complexity would be O(1). One might argue that we are using another list to store our result so the space complexity should also be O(m + n). But this is the list we are not using for our algorithm, we are using it for the result which is asked in the question (I’d love to know your take on this).

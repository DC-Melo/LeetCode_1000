/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Compare
{
    bool operator()(const ListNode*p, const ListNode* q)const{
        return p->val > q->val;
    }
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int length = lists.size();
        ListNode *head = new ListNode(0);
        ListNode *pointer = head;
        /* 既然是队列那么先要包含头文件#include <queue>, 他和queue不同的就在于我们可以自定义其中数据的优先级, 让优先级高的排在队列前面,优先出队 */
        priority_queue<ListNode*, vector<ListNode*>, Compare> listQueue;
        
        for (int i=0; i<length; i++)
        {
            if (lists[i])
                listQueue.push(lists[i]);
        }
        
        while (listQueue.size() > 0)
        {
            ListNode* tempNode = listQueue.top();
            listQueue.pop();
            pointer->next = tempNode;
            pointer = pointer->next;
            if (tempNode->next)
                listQueue.push(tempNode->next);
        }
        pointer->next = NULL;
        return head->next;
    }
};
int main(){
    Solution sln;
    int N;
    vector<ListNode*> lists;
    cout << "input the vector<ListNode*> N:";
    cin >> N;

    ListNode *head,*last,*pcur;
    head = new ListNode(0); //添加链表头
    for (int i=0;i<N;i++){
        last = head;  
        int j;
        cout << "input the link node";
        while((scanf("%d", &j)) != EOF){
            pcur = new ListNode(j);
            last->next = pcur;
            last = pcur;
        }
        lists.push_back(head->next);
    }

    cout << "the vector<ListNode*> " << N << endl;
    for (int i=0;i<N;i++){
        pcur = lists[i];
        while (pcur) {
            printf("-> %d ", pcur->val);
            pcur = pcur->next;
        }
        printf("\n");
    }
    pcur=sln.mergeKLists(lists);
    cout << "the return list node " << endl;
    while (pcur) {
        printf("-> %d ", pcur->val);
        pcur = pcur->next;
    }
    printf("\n");
}
    


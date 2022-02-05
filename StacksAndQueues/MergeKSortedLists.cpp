/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//One optimization here is to use the existing nodes itself without creating new nodes everytime. 
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *answer = new ListNode();
    ListNode *returner = answer;
    priority_queue<pair<int, int>> pq;
    //if the input is [], then it will not go into the for loop, and hence not into the while loop
    for (int i = 0; i < lists.size(); i++)
    {
        //If the node in the list is NULL then list->val will throw error
        //This makes sure when the input is like [[][][]], the output is correct
        if (!lists[i])
            continue;
        pq.push({-lists[i]->val, i});
        lists[i] = lists[i]->next;
    }
    while (!pq.empty())
    {
        answer->next = new ListNode(-pq.top().first);
        answer = answer->next;
        int index = pq.top().second;
        if (lists[index])
        {
            pq.push({-lists[index]->val, index});
            lists[index] = lists[index]->next;
        }
        pq.pop();
    }
    return returner->next;
}

int main()
{
    //Input: lists = [[1,4,5],[1,3,4],[2,6]]
    //Output: [1,1,2,3,4,4,5,6]
}
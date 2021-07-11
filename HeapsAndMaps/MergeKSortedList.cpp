#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct CustomCompare {
    bool operator()(ListNode* const& p1, ListNode* const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1->val > p2->val;
    }
};
ListNode* MergeKSortedLists(vector<ListNode*> A){
       priority_queue<ListNode*,vector<ListNode*>,CustomCompare> pq;
    for(int i=0;i<A.size();i++){
        ListNode* l = A[i];
        while(l){
            pq.push(l);
            l = l->next;
        }
    }
    vector<ListNode*> v;
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    for(int i=0;i<v.size()-1;i++){
        v[i]->next = v[i+1];
    }
    v[v.size()-1]->next = NULL;
    return v[0];
}
int main(){

    return 0;
}
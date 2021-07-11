#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
};
class LinkedList{
    public:
    struct ListNode *head;
    int size;
    LinkedList(ListNode* x) : head(x),size(1){}
    LinkedList():head(NULL),size(0){}
    ListNode* addNode(int value);
    ListNode* addBegin(int value);
    ListNode* deleteNode(int value);
    int search(int value);
    void displayList();
    ListNode* reverseList();
    
};
ListNode* RemoveDuplicates(ListNode* A){
    if(A==NULL)return A;
    ListNode* start = A;
    ListNode* temp = A;
    while(temp!=NULL){
        ListNode* s = temp;
        // 1 2 3 3 3 4 5 5
        while(temp->next!=NULL && temp->next->val==temp->val){
            temp = temp->next;
        }
        temp = temp->next;
        s->next = temp;
    }
    return start;    
}
ListNode* LinkedList::addNode(int value){
    ListNode* A  = head;
    if (head == NULL)
    {
        ListNode* B;
        B = new (struct ListNode);
        B->val = value;
        B->next = NULL;
        head = B;
        return head;
    }
    ListNode* start = A;
    while(A->next!=NULL){
        A = A->next;
    }
    ListNode* B;
    B = new (struct ListNode);
    B->val = value;
    B->next = NULL;
    A->next = B;
    return start;
}
ListNode* LinkedList::addBegin(int value){
    if (head == NULL)
    {   struct ListNode* B;
        B = new (struct ListNode);
        B->val = value;
        B->next = NULL;
        head = B;
        return head;
    }
    ListNode* current = new (struct ListNode);
    current->val = value;
    current->next = head;
    head = current;
    return current;
}
int LinkedList::search(int value){
    int count=1;
    ListNode* A = head;
    while(A!=nullptr){
        if(A->val==value)return count;
        A = A->next;
        count++;
    }
    return -1;
}
void LinkedList::displayList(){
    ListNode* A = head;
    while(A!=NULL){
        cout<<A->val;
        if(A->next)cout<<"->";
        A = A->next;
    }
    cout<<endl;
    return;
}
ListNode* LinkedList::reverseList(){
    ListNode *current = head,*prev=NULL,*next=NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

pair<ListNode*,int> findMiddle(ListNode* A){
    if(A==NULL)return {A,0};
    ListNode* slow=A,*fast=A;
    int s=1;
    while(fast!=NULL && fast->next!=NULL){
        s+=2;
        fast = fast->next->next;
        slow=slow->next;
    }
    if(fast==NULL)s-=1;
    return {slow,s};
}

void kthNodeFromEnd(ListNode* A,int k){
    static int i=0;
    if(A==NULL)return;
    kthNodeFromEnd(A->next,k);
    if(++i==k)cout<<A->val;
}

int kthNodeFromMiddle(ListNode* A,int B){
    ListNode* middle = findMiddle(A).first;
    if(B==0)return middle->val;
    while(middle->next && B--){
        middle = middle->next;
    }
    if(B==0)return middle->val;
    return -1;
}

int kthNodeFromMiddleTowardsBeginning(ListNode* A,int B){
   ListNode* head = A;
   size_t n=0;
    while(head){
       head = head->next;
       n++;
    }
    int required = (n/2)+1-B;
    cout<<required<<endl;
    if(required<=0)return -1;
    n=0;
    while(A){
        n++;
        if(n==required)return A->val;
        A = A->next;
    }
    return -1;
}
bool PalindromeList(ListNode* A){
    vector<int> v;
    while(A){
        v.push_back(A->val);
        A = A->next;
    }
    int n = v.size();
    for(int i=0;i<n/2;i++){
        if(v[i] != v[n-i-1])return false;
    }
    return true;
}

bool PalindromeCheck(ListNode* A){
    //Does in O(n) time and O(1) space
    pair<ListNode*,int>  p = findMiddle(A);
    ListNode* middle = p.first;
    int size = p.second;
    if(size&1)middle=middle->next;
    ListNode* prev=NULL,*next=NULL,*init = A;
    while(A!=middle){
        next = A->next;
        A->next = prev;
        prev = A;
        A = next;
    }   
    init->next = middle;
    //Now the head is prev
    if(size&1)prev = prev->next;
    middle = findMiddle(prev).first;
    while(middle!=NULL){
        if(prev->val!=middle->val)return false;
        prev = prev->next;
        middle = middle->next;
    }
    return true;
}

int main(){
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(14);
    ll.addNode(6);
    ll.addNode(15);
    ll.addNode(15);
    ll.addNode(6);
    ll.addNode(14);
    ll.addNode(1);
    cout<<PalindromeCheck(ll.head);
    return 0;
}
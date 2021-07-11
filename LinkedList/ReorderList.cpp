#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
};

class LinkedList{
    public:
    struct ListNode *head;
    int size;
    //LinkedList(ListNode* x) : head(x),size(1);
    //LinkedList():head(NULL),size(0);
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
    ListNode* prev;
    while(fast!=NULL && fast->next!=NULL){
        s+=2;
        fast = fast->next->next;
        prev = slow;
        slow=slow->next;
    }
    if(fast==NULL)s-=1;
    return {prev,s};
}
ListNode* reverseList(ListNode* A){
    ListNode* next = NULL, *prev = NULL;
    while(A){
        next = A->next;
        A->next = prev;
        prev = A;
        A = next;
    }
    return prev;
}

ListNode* ReorderList(ListNode* A){
    pair<ListNode*,int> p = findMiddle(A);
    ListNode* head = A;
    ListNode* middle = p.first;
    int size = p.second;
    if(size==1)return A;
    if(size&1)middle = middle->next;
    ListNode* breaker = middle->next;
    middle->next = reverseList(middle->next);
    middle = middle->next;
    ListNode* next;
    while(middle!=breaker){
        next = A->next;
        A->next = middle;//middle->next = next;
        ListNode* middleNext = middle->next;
        middle->next = next;
        A = next;
        middle = middleNext;
    }
    next = A->next;
    A->next = middle;
    if(size&1){
        A->next->next =next;
        A->next->next->next = NULL;
    }
    return head;
}

void displayList(ListNode* A){
    while(A){
        cout<<A->val;
        if(A->next)cout<<"->";
        A = A->next;
    }
    return;
}

int main(){
    LinkedList ll;
    ll.addNode(10);
    ll.addNode(20);
    ll.addNode(30);
    ll.addNode(40);
    ll.addNode(50);
    ll.addNode(60);
    ll.addNode(70);
    ll.addNode(80);
    //ll.addNode(90);
    ListNode* head = ReorderList(ll.head);
    displayList(head);
    return 0;
}
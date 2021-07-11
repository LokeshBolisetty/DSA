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
    void displayList(ListNode* A);
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

void LinkedList::displayList(ListNode* A){
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

ListNode* SwapListNodes(ListNode* A){
    if(A==NULL)return A;
    ListNode* l=NULL;
    if(!A->next)return A;
    if(A->next && A->next->next)l = SwapListNodes(A->next->next);
    ListNode* p = A->next;
    p->next = A;
    A->next = l;
    return p;
}

ListNode* ReverseAlternateKNodes(ListNode* A,int k){
    /*
        Given a linked list A of length N and an integer B.

        You need to reverse every alternate B nodes in the linked list A.

    */
    if(k==1)return A; //if K is 1 there is no need to change anything
    int count=0;
    ListNode* prev = NULL, *next = NULL,*head=A;
    while(count<k){ //Reversing the first k elements
        count++;
        if(!A && count<k)return head;
        next = A->next;
        A->next = prev;
        prev = A;
        A = next;
    }
    head->next = next;
    count=0;
    ListNode* dup = prev;
    ListNode* previous;
    while(count<k){ //Traversing the next K elements without altering them. 
        if(A==NULL)return dup; //If you reach a point where there aren't enough nodes to reverse, then return the starting Node. 
        //Starting node is the kth node here. 
        previous = A;
        A = A->next;
        count++;
    }
    previous->next = ReverseAlternateKNodes(A,k); //Now with (2*k+1)th Node as the head, call the same function 
    // to reverse the next k elements and skip the following k. 
    return prev;
}

int main(){
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.addNode(4);
    ll.addNode(5);
    ll.addNode(6);
    ListNode* head = ReverseAlternateKNodes(ll.head,1);
    ll.displayList(head);
    return 0;
}
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

ListNode* ReverseNodesinK(ListNode* A,int k){
    if(A==NULL)return A;
    ListNode* head = A;
    ListNode* l = NULL;
    int count=0;
    while(count<k){
        count++;
        
        A = A->next;
        if(A==NULL && count<k)return head;
    }l = ReverseNodesinK(A,k);
    ListNode* ntp = head;
    ListNode *current = head,*prev=NULL,*next=NULL;
    while(current!=A){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    ntp->next = l;
    return head;
}
int main(){
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.addNode(4);
    ll.addNode(5);
    ll.addNode(6);
    ListNode* head = ReverseNodesinK(ll.head,1);
    ll.displayList(head);
    return 0;
}
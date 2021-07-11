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

ListNode* reverseFromMtoN(ListNode* A,int m,int n){
    ListNode* head = A,*temp=A,*prev;
    for(int i=1;i<=m-1;i++){
        prev = temp;
        temp = temp->next;
    }
    ListNode* LastUnreversed = prev,*change=NULL;
    ListNode* p=NULL,*next=NULL;
    n -=m;
    n++;
    bool flag=true;
    while(n--){
        next = temp->next;
        temp->next = p;
        if(flag)change=temp;
        flag=false;
        p = temp;
        temp = next;
    }
    if(m==1)head = p;
    change->next = next;
    //LastUnreversed->next->next = temp;
    LastUnreversed->next=p;
    return head;
}

ListNode* reverseBetween(ListNode* A, int B, int C) {//Editorial Solution
    if(B != 1){ // if B is not the first element 
        A->next = reverseBetween(A->next, B-1, C-1);// pass the next element decreasing B and C
        return A;
    }
    else{ // if B is the first element
        ListNode *prev=NULL, *curr=A, *next=NULL;
        int count=0;
        while(count<C){ // reverse the list till C 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        A->next = curr;// Append the first list element to the C+1 element
        return prev;// return the new start
    }
}


int main(){
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.addNode(4);
    ll.addNode(5);
    ListNode* A  = reverseFromMtoN(ll.head,1,3);
    //cout<<cycleDetection(ll.head)->val<<endl;
    ll.displayList(A);
    return 0;
    // 1->2->3->4->5
}
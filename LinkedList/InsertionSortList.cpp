#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INT_MAX 2147483647
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int value):val(value){}
    ListNode():next(NULL){}
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

ListNode* InsertionSort(ListNode* A){
    ListNode* temp = new ListNode(INT_MAX);
    ListNode* head = A,*prev = A,*tempPrev=NULL;
    while(A){
        if(A->val<temp->val){
            temp = A;
            tempPrev=prev;
        }
        prev = A;
        A = A->next;
    }
    A = head;
    if(A==temp){
        A = A->next;
        head = head->next;
    }
    else //Deleting temp from there;
    tempPrev->next = temp->next;
    ListNode* returner = temp;
    while(A!=NULL){
        ListNode* temper = new ListNode(INT_MAX),*temperPrev = NULL;
        temper->val = INT_MAX;
        while(A){
            if(A->val<temper->val){
                temper = A;
                temperPrev = prev;
            }
            prev = A;
            A = A->next;
        }
        A = head;
        if(temper==A){
            temp->next = temper;
            A= A->next;
            head = head->next;
            temp = temp->next;
        }
        else{
            temperPrev->next = temper->next;
            temp->next = temper;
            temp = temp->next;
        }
    }
    return returner;
}

ListNode* Editorial(ListNode* A) {
    //Insertion Sort
    ListNode* ptr1=A->next;
    if(ptr1==NULL)
    return A;
    while(ptr1!=NULL){
        ListNode* ptr2=A;
        while(ptr2!=ptr1){
            if(ptr2->val > ptr1->val)
            swap(ptr2->val,ptr1->val);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return A;
}



int main(){
    LinkedList ll;
        ll.addNode(1);
        ll.addNode(4);
        ll.addNode(3);
        ll.addNode(5);
        ll.addNode(5);
        ll.addNode(6);
        ll.addNode(4);
        ll.addNode(1);
    ListNode* head = InsertionSort(ll.head);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}
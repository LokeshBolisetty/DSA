#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int value): val(value){}
    ListNode() : next(NULL) {}
};

class LinkedList
{
public:
    struct ListNode *head;
    int size;
    //LinkedList(ListNode* x) : head(x),size(1);
    //LinkedList():head(NULL),size(0);
    ListNode *addNode(int value);
    ListNode *addBegin(int value);
    ListNode *deleteNode(int value);
    int search(int value);
    void displayList();
    ListNode *reverseList();
};

ListNode *RemoveDuplicates(ListNode *A)
{
    if (A == NULL)
        return A;
    ListNode *start = A;
    ListNode *temp = A;
    while (temp != NULL)
    {
        ListNode *s = temp;
        // 1 2 3 3 3 4 5 5
        while (temp->next != NULL && temp->next->val == temp->val)
        {
            temp = temp->next;
        }
        temp = temp->next;
        s->next = temp;
    }
    return start;
}

ListNode *LinkedList::addNode(int value)
{
    ListNode *A = head;
    if (head == NULL)
    {
        ListNode *B;
        B = new (struct ListNode);
        B->val = value;
        B->next = NULL;
        head = B;
        return head;
    }
    ListNode *start = A;
    while (A->next != NULL)
    {
        A = A->next;
    }
    ListNode *B;
    B = new (struct ListNode);
    B->val = value;
    B->next = NULL;
    A->next = B;
    return start;
}

ListNode *LinkedList::addBegin(int value)
{
    if (head == NULL)
    {
        struct ListNode *B;
        B = new (struct ListNode);
        B->val = value;
        B->next = NULL;
        head = B;
        return head;
    }
    ListNode *current = new (struct ListNode);
    current->val = value;
    current->next = head;
    head = current;
    return current;
}

int LinkedList::search(int value)
{
    int count = 1;
    ListNode *A = head;
    while (A != nullptr)
    {
        if (A->val == value)
            return count;
        A = A->next;
        count++;
    }
    return -1;
}

void LinkedList::displayList()
{
    ListNode *A = head;
    while (A != NULL)
    {
        cout << A->val;
        if (A->next)
            cout << "->";
        A = A->next;
    }
    cout << endl;
    return;
}

ListNode *LinkedList::reverseList()
{
    ListNode *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

ListNode *findMiddle(ListNode *A)
{
    ListNode *slow = A, *fast = A;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void kthNodeFromEnd(ListNode *A, int k)
{
    static int i = 0;
    if (A == NULL)
        return;
    kthNodeFromEnd(A->next, k);
    if (++i == k)
        cout << A->val;
}

int kthNodeFromMiddle(ListNode *A, int B)
{
    ListNode *middle = findMiddle(A);
    if (B == 0)
        return middle->val;
    while (middle->next && B--)
    {
        middle = middle->next;
    }
    if (B == 0)
        return middle->val;
    return -1;
}

int kthNodeFromMiddleTowardsBeginning(ListNode *A, int B)
{
    ListNode *head = A;
    size_t n = 0;
    while (head)
    {
        head = head->next;
        n++;
    }
    int required = (n / 2) + 1 - B;
    cout << required << endl;
    if (required <= 0)
        return -1;
    n = 0;
    while (A)
    {
        n++;
        if (n == required)
            return A->val;
        A = A->next;
    }
    return -1;
}

ListNode *MergeTwoSortedList(ListNode *A, ListNode *B)
{
    ListNode *C = NULL, *returner;
    while (A && B)
    {
        if (A->val < B->val)
        {
            if (!C)
            {
                C = A;
                returner = C;
            }
            else
            {
                C->next = A;
                C = C->next;
            }
            A = A->next;
        }
        if (A && B && A->val >= B->val)
        {
            if (!C)
            {
                C = B;
                returner = C;
            }
            else
            {
                C->next = B;
                C = C->next;
            }
            B = B->next;
        }
    }
    while (A)
    {
        if (!C)
        {
            C = A;
            A = A->next;
            returner = C;
        }
        else
        {
            C->next = A;
            C = C->next;
            A = A->next;
        }
    }
    while (B)
    {
        if (!C)
        {
            C = B;
            returner = C;
            B = B->next;
        }
        else
        {
            C->next = B;
            C = C->next;
            B = B->next;
        }
    }
    return returner;
}

ListNode* MergeWithoutExtraSpace(ListNode* A, ListNode* B) {
if( A==NULL ) return B;
if( B==NULL) return A;

struct ListNode* a = A;
struct ListNode* b= B;
struct ListNode *prev= NULL;
if( A->val > B->val ) {
    return MergeWithoutExtraSpace( B,A);
}
while( a &&b){
    
    if( a->val == b->val ){
        prev= a;
        a= a->next;
        prev->next = new ListNode ( b->val ) ;
        prev= prev->next;
        prev->next= a;
        b= b->next;
    }
    else if( a->val > b->val){
        prev->next = new ListNode( b->val);
        prev= prev->next;
        prev->next = a;
        b= b->next;
       // cout<<prev->val<<" "<<a->val<<endl;
    }
    else {
        prev= a;
        a= a->next;
    }
    
}
while( a== NULL && b){
    prev->next = new ListNode(b->val);
    prev= prev->next;
    b= b->next;
}

return A ;

}

int main()
{
    LinkedList ll;
        ll.addNode(1);
        ll.addNode(2);
        ll.addNode(4);
        ll.addNode(6);
        ll.addNode(8);
        ll.addNode(10);
        ll.addNode(12);
        ll.addNode(14);
        ll.addNode(16);
    LinkedList ll2;
        ll2.addNode(1);
        ll2.addNode(5);
        ll2.addNode(7);
        ll2.addNode(9);
        ll2.addNode(11);
        ll2.addNode(13);
        ll2.addNode(15);
        ll2.addNode(17);
        ll2.addNode(19);
    ListNode *C = MergeWithoutExtraSpace(ll.head, ll2.head);
    while (C)
    {
        cout << C->val << " ";
        C = C->next;
    }
    return 0;
}
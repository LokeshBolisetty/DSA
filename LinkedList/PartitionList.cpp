#include <iostream>
#include <queue>
using namespace std;
#define INT_MAX 2147483647
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int value) : val(value) {}
    ListNode() : next(NULL) {}
};

class LinkedList
{
public:
    struct ListNode *head;
    int size;
    LinkedList(ListNode *x) : head(x), size(1) {}
    LinkedList() : head(NULL), size(0) {}
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

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/
ListNode *PartitionList(ListNode *A,int B)
{
    /*
    Maintain 2 pointers - one which maintains all nodes less than x and another which maintains nodes greater than or equal to x.
    Keep going along our list. When we are at node that is greater than or equal to x, we remove this node from our list and move it to list of nodes greater than x.
    */
    ListNode *temp1 = new ListNode(0);
    ListNode *temp2 = new ListNode(0);
    ListNode *start1 = temp1, *start2 = temp2;
    while (A)
    {

        if (A->val < B)
        {

            start1->next = A;
            A = A->next;
            start1 = start1->next;
        }

        else
        {

            start2->next = A;
            A = A->next;
            start2 = start2->next;
        }
    }

    start1->next = temp2->next;

    start2->next = NULL;

    return temp1->next;
}

int main()
{
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(4);
    ll.addNode(3);
    ll.addNode(5);
    ll.addNode(5);
    ll.addNode(6);
    ll.addNode(4);
    ll.addNode(1);
    cout << endl;
    return 0;
}
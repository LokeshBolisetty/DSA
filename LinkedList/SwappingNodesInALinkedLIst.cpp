#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data,Node* next,Node* prev):data(data),next(next),prev(prev){}
    Node(int data):data(data),next(NULL),prev(NULL){}
};

Node* createLinkedList(vector<int> v){
    if(v.size()==0)return NULL;
    Node* head = new Node(v[0]);
    Node* returner = head;
    Node* prev;
    for(int i=1;i<v.size();i++){
        head->next = new Node(v[i]);
        prev = head;
        head = head->next;
        head->prev = prev;
    }
    returner->prev = prev;
    return returner;
}

void printList(Node* head){
    if(!head)cout<<"The list is empty\n";
    cout<<"The Linked List is "<<head->data;
    Node* actualHead = head;
    head = head->next;
    while(head && head!=actualHead){
        cout<<"\t"<<head->data;
        head = head->next;
    }
    cout<<endl;
    return;
}

Node* addFirst(Node* head,int data){
    Node* newHead = new Node(data);
    newHead->next = head;
    newHead->prev = head->prev;
    head->prev = newHead;
    return newHead;
}

Node* addLast(Node* head,int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    Node* returner = head;
    while(head->next){
        head = head->next;
    }
    head->next = newNode;
    return returner;
}

Node* deleteNode(Node* head,int data){
    Node* returner =  head;
    if(head->data==data) returner = head->next;
    while(head && head->data!=data){
        head = head->next;
    }
    if(!head)return returner;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    return returner;
}

int find(Node* head,int data){
    int idx = 0;
    while(head && head->data != data){
        head = head->next;
        idx++;
    }
    if(!head)return -1;
    return idx;
}

Node* swapNodes(Node* head, int k) {
    Node* kFromStart;
    Node* kFromEnd = head;
    Node* returner = head;
    int i = 1;
    while(head){
        if(i==k)break;
        head = head->next;
        i++;
    }
    kFromStart = head;
    while(head->next!=NULL){
        head = head->next;
        kFromEnd = kFromEnd->next;
    }
    //Now swap kFromStart and KFromEnd
    int dummy = kFromEnd->data;
    kFromEnd->data = kFromStart->data;
    kFromStart->data = dummy;
    return returner;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    Node* head = createLinkedList(v);
    printList(head);
    int k = 2;
    swapNodes(head, k);
    printList(head);
    return 0;
}
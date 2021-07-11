#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* IPreTree(int pre[],int in[],int left,int right){
    static int preindex = 0;
    if(left>right) return NULL;
    Node* newNode = new Node(pre[preindex]);
    preindex++;
    if(left == right){
        return newNode;
    }
    int inIndex = m[newNode->data];
    newNode->left = IPreTree(pre,in,left,inIndex-1);
    newNode->right = IPreTree(pre,in,inIndex+1,right);
    return newNode;
}

Node* IPostTree(int post[],int in[],int size,int left,int right){
    static int postIndex = size;
    if(left>right) return NULL;
    Node* newNode = new Node(post[postIndex]);
    postIndex--;
    if(left == right){
        return newNode;
    }
    int inIndex = m[newNode->data];
    newNode->right = IPostTree(post,in,size,inIndex+1,right);
    newNode->left = IPostTree(post,in,size,left,inIndex-1);
    
    return newNode;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

void printPreorder(Node* node){
    if(node==NULL)return;
    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node){
    if(node==NULL)return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}

void printLevelorder(Node* node){
    deque<Node*> s;
    s.push_back(node);
    while(!s.empty()){
        Node* n = s.front();
        if(n->left)
        s.push_back(n->left);
        if(n->right)
        s.push_back(n->right);
        cout<<s.front()->data<<" ";
        s.pop_front();
    }
    cout<<"\n";
}

vector<int> TreetoArray(Node* node){
    deque<Node*> s;
    vector<int> v;
    s.push_back(node);
    while(!s.empty()){
        Node* n = s.front();
        if(n->left)
        s.push_back(n->left);
        if(n->right)
        s.push_back(n->right);
        v.push_back(n->data);
        s.pop_front();
    }
    return v;
}

int height(Node* node){
    if(node==NULL)return 1;
    return max(height(node->left),height(node->right))+1;
}

bool ValidBSTFromPreorder(vector<int> pre){
    stack<int> s;
    int root = INT_MIN;
    for(int i=0;i<pre.size();i++){
        while(!s.empty() && pre[i]>s.top()){
            root = s.top();
            s.pop();
        }
        if(pre[i]<root)return false;
        s.push(pre[i]);
    }
    return true;
}

int main(){
    vector<int> pre = {44,22,11,66,55,33,77,88};
    cout<<ValidBSTFromPreorder(pre)<<endl;
    return 0;
}
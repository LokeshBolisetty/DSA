#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* IPreTree(int pre[],int in[],int left,int right){
    static int preindex = 0;
    if(left>right) return NULL;
    TreeNode* newTreeNode = new TreeNode(pre[preindex]);
    preindex++;
    if(left == right){
        return newTreeNode;
    }
    int inIndex = m[newTreeNode->data];
    newTreeNode->left = IPreTree(pre,in,left,inIndex-1);
    newTreeNode->right = IPreTree(pre,in,inIndex+1,right);
    return newTreeNode;
}

TreeNode* IPostTree(int post[],int in[],int size,int left,int right){
    static int postIndex = size;
    if(left>right) return NULL;
    TreeNode* newTreeNode = new TreeNode(post[postIndex]);
    postIndex--;
    if(left == right){
        return newTreeNode;
    }
    int inIndex = m[newTreeNode->data];
    newTreeNode->right = IPostTree(post,in,size,inIndex+1,right);
    newTreeNode->left = IPostTree(post,in,size,left,inIndex-1);
    
    return newTreeNode;
}

void printInorder(TreeNode* Treenode)
{
    if (Treenode == NULL)
        return;
    printInorder(Treenode->left);
    cout<<Treenode->data<<" ";
    printInorder(Treenode->right);
}

void printPreorder(TreeNode* Treenode){
    if(Treenode==NULL)return;
    cout<<Treenode->data<<" ";
    printPreorder(Treenode->left);
    printPreorder(Treenode->right);
}

void printPostorder(TreeNode* Treenode){
    if(Treenode==NULL)return;
    printPostorder(Treenode->left);
    printPostorder(Treenode->right);
    cout<<Treenode->data<<" ";
}

void printLevelorder(TreeNode* Treenode){
    deque<TreeNode*> s;
    s.push_back(Treenode);
    while(!s.empty()){
        TreeNode* n = s.front();
        if(n->left)
        s.push_back(n->left);
        if(n->right)
        s.push_back(n->right);
        cout<<s.front()->data<<" ";
        s.pop_front();
    }
    cout<<"\n";
}

vector<int> TreetoArray(TreeNode* Treenode){
    deque<TreeNode*> s;
    vector<int> v;
    s.push_back(Treenode);
    while(!s.empty()){
        TreeNode* n = s.front();
        if(n->left)
        s.push_back(n->left);
        if(n->right)
        s.push_back(n->right);
        v.insert(v.begin(),n->data);
        s.pop_front();
    }
    return v;
}

int height(TreeNode* Treenode){
    if(Treenode==NULL)return 1;
    return max(height(Treenode->left),height(Treenode->right))+1;
}

void printGivenLevel(TreeNode* A,int height,vector<int> &ans){
    if(A==NULL)return;
    if(height==1)ans.push_back(A->data);
    else{
        printGivenLevel(A->left,height-1,ans);
        printGivenLevel(A->right,height-1,ans);
    }
}
vector<int> reverseLevelOrder(TreeNode* A){
    int h = height(A);
    vector<int> ans;
    for(int i=h;i>0;i--){
        printGivenLevel(A,i,ans);
    }
    return ans;
}
vector<int> ReverseLevelOrderWithStack(TreeNode* A){
    stack<TreeNode*> s;
    vector<int> v;
    queue<TreeNode*> q;
    while(!q.empty()){
        TreeNode* n = q.front();
        q.pop();
        s.push(n);
        if(n->right)q.push(n->right);
        if(n->left)q.push(n->left);
    }
    while(!s.empty()){
        v.push_back(s.top()->data);
        s.pop();
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    int pre[n],in[n];
    //Take inorder inpupt
    for(int i =0;i<n;i++){
        cin>>in[i];
        m.insert({in[i],i});
        cin.ignore();
    }
    //Take preorder input
    for(int i =0;i<n;i++){
        cin>>pre[i];
        cin.ignore();
    }

    TreeNode* root = IPreTree(pre,in,0,n-1);
    printLevelorder(root);
    return 0;
}
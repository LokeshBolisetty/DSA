/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int data):data(data){}
};

TreeNode* buildTree(vector<int> input){
    queue<TreeNode*>  q;
    if(input.size()==0)return NULL;
    TreeNode* root = new TreeNode(input[0]);
    q.push(root);
    int idx = 1;
    while(!q.empty() && idx<input.size()){
        TreeNode* temp = q.front();
        temp->left = input[idx] == -1 ? NULL : new TreeNode(input[idx]);
        if(temp->left)q.push(temp->left);
        idx++;
        temp->right = input[idx] == -1? NULL : new TreeNode(input[idx]);
        if(temp->right)q.push(temp->right);
        idx++;
        q.pop();
    }
    return root;
}

TreeNode* increasingBST(TreeNode* root) {
    if(root==NULL || (root->left==NULL && root->right==NULL) )return root;
    TreeNode* returner=root;
    if(root->left)returner = increasingBST(root->left);
    TreeNode* right = NULL;
    if(root->right) right = increasingBST(root->right);
    if(root->data==22){
        cout<<"Hello"<<endl;
    }
    if(root->left){
        TreeNode* rightMost = returner;
        while(rightMost->right) rightMost = rightMost->right;
        rightMost->right = root;
        root->left = NULL;
    }

    if(root->right){
        root->right = right;
    }
    return returner;
}

void inorder(TreeNode* root){
    if(root->left)inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)inorder(root->right);
}


int main(){
    vector<int> input = {20,8,22,5,3,-1,25,-1,-1,10,14,-1,-1};
    //vector<int> input = {8,5,3,-1,-1,10,14};
    TreeNode* root = buildTree(input);
    root = increasingBST(root);
    inorder(root);
    return 0;
}
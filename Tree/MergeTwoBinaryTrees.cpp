#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) {
        val = d;
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
    int inIndex = m[newTreeNode->val];
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
    int inIndex = m[newTreeNode->val];
    newTreeNode->right = IPostTree(post,in,size,inIndex+1,right);
    newTreeNode->left = IPostTree(post,in,size,left,inIndex-1);
    
    return newTreeNode;
}

void printInorder(TreeNode* Treenode)
{
    if (Treenode == NULL)
        return;
    printInorder(Treenode->left);
    cout<<Treenode->val<<" ";
    printInorder(Treenode->right);
}

void printPreorder(TreeNode* Treenode){
    if(Treenode==NULL)return;
    cout<<Treenode->val<<" ";
    printPreorder(Treenode->left);
    printPreorder(Treenode->right);
}

void printPostorder(TreeNode* Treenode){
    if(Treenode==NULL)return;
    printPostorder(Treenode->left);
    printPostorder(Treenode->right);
    cout<<Treenode->val<<" ";
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
        cout<<s.front()->val<<" ";
        s.pop_front();
    }
    cout<<"\n";
}

TreeNode* MergeTrees(TreeNode* A,TreeNode* B){
    if(A && B){
        A->val = A->val+B->val;
        A->left = MergeTrees(A->left,B->left);
        A->right = MergeTrees(A->right,B->right);
        return A;
    }
    else return A?A:B;
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
    TreeNode* A = IPreTree(pre,in,0,n-1);
    cin>>n;
    int pre2[n],in2[n];
    m.clear();
    //Take inorder inpupt
    for(int i =0;i<n;i++){
        cin>>in2[i];
        m.insert({in[i],i});
        cin.ignore();
    }
    //Take preorder input
    for(int i =0;i<n;i++){
        cin>>pre2[i];
        cin.ignore();
    }
    TreeNode* B = IPreTree(pre2,in2,0,n-1);
    printInorder(A);
    return 0;
}
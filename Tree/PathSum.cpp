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

int count(TreeNode* root){
    if(!root)return 0;
    return 1+count(root->left)+count(root->right);
}

TreeNode* invertTree(TreeNode* A) {
    TreeNode* spare = A->right;
    if(A->left && A->right){
        A->right = A->left;
        A->left = spare;
    }
    else if(!A->left && A->right){
        A->left = A->right;
        A->right = NULL;
    }else if(A->left && !A->right){
        A->right = A->left;
        A->left = NULL;
    }
    if(A->left){
        invertTree(A->left);
    }
    if(A->right){
        invertTree(A->right);
    }
    return A;
}
bool checkSum(TreeNode* A,int sum,int req){
    if(A==NULL)return false;
    sum+=A->data;
    if(sum==req && A->left==NULL && A->right==NULL){
        return true;
    }
    return checkSum(A->left,sum,req)||checkSum(A->right,sum,req);
}
int hasPathSum(TreeNode* A, int B) {
    return checkSum(A,0,B);
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
    cout<<hasPathSum(root,10000)<<endl;
    return 0;
}
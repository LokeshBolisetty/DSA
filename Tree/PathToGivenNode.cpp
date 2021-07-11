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
    TreeNode* newNode = new TreeNode(pre[preindex]);
    preindex++;
    if(left == right){
        return newNode;
    }
    int inIndex = m[newNode->val];
    newNode->left = IPreTree(pre,in,left,inIndex-1);
    newNode->right = IPreTree(pre,in,inIndex+1,right);
    return newNode;
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
        v.insert(v.begin(),n->val);
        s.pop_front();
    }
    return v;
}

bool Path(TreeNode* A,vector<int> &ans,int B){
    if(A==NULL)return false;
    ans.push_back(A->val);
    if(A->val==B){
        return true;
    }
    else{
        if(Path(A->left,ans,B)){
            return true;
        }else if(Path(A->right,ans,B)){
            return true;
        }else{
            ans.pop_back();
        }
    }
    return false;
}

vector<int> PathToGivenNode(TreeNode* A,int B){
    vector<int> ans;
    Path(A,ans,B);
    return ans;
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
    vector<int> path = PathToGivenNode(root,13);
    for(auto x:path)cout<<x<<" ";
    cout<<endl;
    return 0;
}
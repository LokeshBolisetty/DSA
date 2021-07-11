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

int printGivenLevel(TreeNode* root,int height){
    static int k = 0;
    if(!root)return 0;
    if(height==1)k=root->data;
    else{
        printGivenLevel(root->left,height-1);
        printGivenLevel(root->right,height-1);
    }
    return k;
}

int height(TreeNode* A){
    if(A==NULL)return 0;
    return max(height(A->left),height(A->right))+1;
}

vector<int> RightView(TreeNode* A){
    int h = height(A);
    vector<int> ans;
    for(int i=1;i<=h;i++){
        ans.push_back(printGivenLevel(A,i));
    }
    return ans;
}

void printLevelOrder(TreeNode* A){
    if(!A)return;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left)q.push(t->left);
        if(t->right)q.push(t->right);
    }
    cout<<endl;
    return;
}
vector<int> rightView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode *t = q.front();
            q.pop();
            
            if(i==0) ans.push_back(t->data);
            if(t->right) q.push(t->right);
            if(t->left) q.push(t->left);
        }
    }
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
    vector<int> v = rightView(root);
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}
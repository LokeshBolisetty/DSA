#include<iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
pair<TreeNode*,int> generateTree(const vector<int> &A,int st){
    if(st>A.size())return {NULL,st+1};
    if(A[st]==-1)return {NULL,st+1};
    TreeNode* root = new struct TreeNode(A[0]);
    pair<TreeNode*,int> p = generateTree(A,st+1);
    root->left = p.first;
    st = p.second;
    p = generateTree(A,st);
    if(st<A.size()){
        root->right = p.first;
        st = p.second;
    }
    return {root,st+1};
}
void inorder(TreeNode* t){
    if(!t)return;
    inorder(t->left);
    cout<<t->val<<" ";
    inorder(t->right);
    return;
}
int main(){
    vector<int> treeNodes = {3,-1,4,-1,-1};
    TreeNode* root = generateTree(treeNodes,0).first;
    inorder(root);
    return 0;
}
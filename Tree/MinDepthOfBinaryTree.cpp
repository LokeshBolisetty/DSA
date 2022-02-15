#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val){};
    TreeNode(int val,TreeNode* left,TreeNode* right):val(val),left(left),right(right){};
};
bool isLeaf(TreeNode* root){
        return root && !root->left && !root->right;
    }
int minDepth(TreeNode* root) {
    if(root==NULL)return 0;
    if(isLeaf(root))return 1;
    return 1+ min(root->left==NULL? INT32_MAX: minDepth(root->left),root->right==NULL ? INT32_MAX : minDepth(root->right));
}
int minDepthBFS(TreeNode* root){
    if(root==NULL)return 0;
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* top = q.front();
            if(isLeaf(top))return level;
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
            q.pop();
        }
        level++;
    }
    return INT32_MAX; //Not necessary. Just for closure.
}
int main(){
    return 0;
}
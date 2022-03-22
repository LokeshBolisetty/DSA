//Level order traversal for Binary tree will be given
//If there is no child, -1 will be given. 
//Null's children will not be given

#include<iostream>
#include<vector>
#include<queue>
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

void inorder(TreeNode* root){
    if(root->left)inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)inorder(root->right);
}

int main(){
    vector<int> input = {3, 8 ,10, -1, 5, 4, 63, 3 ,-1 ,-1 ,-1 ,49 ,-1};
    TreeNode* root = buildTree(input);
    inorder(root);
    return 0;
}
/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) {
    //Just one child? Attach it to the parent
    //Two children? Either one of the children should also be removed, make the other child as the root
    //If the root is not supposed to be there, then either of its children is also not required.
    if(root==NULL)return root;
    TreeNode* returner= NULL;
    //Check if root is supposed to be present or not
    if(root && root->val >= low && root->val <=high){
        returner = root;
        
        //Get the left nodes
        returner->left = trimBST(root->left, low, high);
        //Get the right nodes
        returner->right = trimBST(root->right, low, high);
        return returner;
    }
    
    //If the root is not supposed to present 
    if(low > root->val){
        //Ignore the left part
        return trimBST(root->right, low, high);
    }
    
    return trimBST(root->left, low, high);
}

int main(){

    return 0;
}
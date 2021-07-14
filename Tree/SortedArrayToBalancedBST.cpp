#include<iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* generateTree(vector<int> nodes){
    if(nodes.size()==0||nodes[0]==-1)return NULL;
    TreeNode* root = new struct TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty()){
        int n = q.size();
        for(int idx=0;idx<n;idx++){
            TreeNode* t = q.front();
            q.pop();
            if(nodes[i]!=-1){
                t->left = new struct TreeNode(nodes[i]);
                q.push(t->left);
            }
            else t->left = NULL;
            i++;
            if(nodes[i]!=-1){
                t->right = new struct TreeNode(nodes[i]);
                q.push(t->right);
            }
            else t->right = NULL;
            i++;
        }
    }
    return root;
}

/**
 * Generate the tree which covers the values in A from index st to index end
 * @param st The starting index which has to be considered for generating the tree
 * @param end The ending index which has to be considered for generating the tree
 * */
TreeNode* generator(const vector<int> &A,int st,int end){
    if(st>end)return NULL; //If st>end you clearly reached a point where you dont have any more nodes. Assign NULL to it
    if(st==end)return new struct TreeNode(A[st]); //If start and end are same then it is a leaf node so return a node with same value.
    int mid = (st+end)/2; 
    TreeNode* root = new struct TreeNode(A[mid]); //Create a node which takes the middle most value of the available range. 
    root->left = generator(A,st,mid-1); //Generate the left subtree
    root->right = generator(A,mid+1,end); //Generate the right subtree
    return root; //Return the middlemost value which we assigned as root. 
}
/** 
 * Generate a Binary Search Tree with values given in the vector A
 * @param A A sorted array. The values in the nodes of the generated tree should be taken only from this array
 **/
TreeNode* sortedArrayToBalancedBST(const vector<int> &A){
    //Generate the tree which covers the values from 0 to A.size()-1
    return generator(A,0,A.size()-1);
}

void inOrderTraversal(TreeNode* A){
    if(A==NULL)return;
    if(A->left)inOrderTraversal(A->left);
    cout<<A->val<<" ";
    if(A->right)inOrderTraversal(A->right);
}
int main(){
    vector<int> treeNodes = {1,2,3};
    TreeNode* root = sortedArrayToBalancedBST(treeNodes);
    inOrderTraversal(root);
    return 0;
}

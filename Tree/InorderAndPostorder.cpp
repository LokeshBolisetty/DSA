#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Nodes that can be used to make a tree
 * @param left Pointer to the left subtree
 * @param right Pointer to the right subtree
 * @param val Value of the Node
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * This function generates a tree with given nodes. 
 * @param nodes Vector with values to be placed in the nodes of the tree being generated. 
 * Nodes should be formatted as - level order traversed tree with -1 representing NULL. Children of NULL need not be represented. 
 * */
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
 * Utility function that helps in creating a tree from postorder and inorder traversals. 
 * @param inorder Vector containing the inorder traversal of the tree
 * @param postorder Vector containing the postorder traversal of the tree
 * @param m Map containing the key as the Node-value and value as value as its index in inorder traversal
 * @param st The starting index of postorder traversal that has to be considered for tree generation
 * @param end The ending index of postorder traversal that has to be considered for tree generation
 * @param remaining Number of nodes that have to be added into the tree 
 * */
TreeNode* generate(vector<int> &inorder,vector<int> &postorder,unordered_map<int,int> &m,int st,int end,int &remaining){
    if(st>end)return NULL;
    int post = postorder[remaining];
    TreeNode* root = new struct TreeNode(post);
    remaining--;
    if(st==end)return root;
    int inIdx = m[post];
    root->right = generate(inorder,postorder,m,inIdx+1,end,remaining);
    root->left = generate(inorder,postorder,m,st,inIdx-1,remaining);
    return root;
}

/**
 * Function to generate a tree from inorder and postorder
 * @param inorder Vector containing the inorder traversal of the required tree
 * @param postorder Vector containing the postorder traversal of the required tree
 * */

TreeNode* InPost(vector<int> &inorder,vector<int> &postorder){
    unordered_map<int,int> m;
    for(int i=0;i<inorder.size();i++)m.insert({inorder[i],i});
    int remaining = postorder.size()-1;
    return generate(inorder,postorder,m,0,postorder.size()-1,remaining);
}

void inOrderTraversal(TreeNode* A){
    if(A==NULL)return;
    if(A->left)inOrderTraversal(A->left);
    cout<<A->val<<" ";
    if(A->right)inOrderTraversal(A->right);
}

int main(){
    vector<int> treeNodes = {8,3,10,1,6,-1,14,-1,-1,4,7,13,-1,-1,-1,-1,-1,-1,-1};
    vector<int> postorder = {1,4,7,6,3,13,14,10,8};
    vector<int> inorder = {1,3,4,6,7,8,10,13,14};
    TreeNode* root = InPost(inorder,postorder);
    inOrderTraversal(root);
    cout<<endl;
    return 0;
}
#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>
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
 * This is a utility function to generate a Max Cartesian Tree
 * @param A Vector containing values for the nodes
 * @param st Starting index of the vector which has to be considered to generate the tree
 * @param end Ending index of the vector which has to be considered to generate the tree
 * It creates a tree with values raning from index st to index end in A
 * */
TreeNode* generateCartesianTree(vector<int> &A,int st,int end){
    if(st>end)return NULL;
    int idx = max_element(A.begin()+st,A.begin()+end+1)-A.begin();
    TreeNode* root = new struct TreeNode(A[idx]); //Maximum element will always act as the root
    root->left = generateCartesianTree(A,st,idx-1); //The elements left to root will become the left subtree because in a Cartesian tree the,
    //the inorder traversal should yield the nodes in the same order as the appear in the initial list. 
    root->right = generateCartesianTree(A,idx+1,end); //All the nodes right to the root will be a part of the right subtree for the same reason. 
    return root;
}

/**
 * Generates a cartesian tree
 * @param A Vector of integers which will act as the values for the Cartesian Tree
 * A Cartesian Tree is a tree that follows either min-heap of max-heap property.
 * This function follows max heap property
 * The other condition for max heap propery is that the inorder traversal of this should give the nodes in same order as they appear in the initial list. 
 * */
TreeNode* CartesianTree(vector<int> &A){
    return generateCartesianTree(A,0,A.size()-1);
}

/**
* Prints the inorder traversal of a tree
* @param A Root of the tree 
**/
void inOrderTraversal(TreeNode* A){
    if(A==NULL)return;
    if(A->left)inOrderTraversal(A->left);
    cout<<A->val<<" ";
    if(A->right)inOrderTraversal(A->right);
}

int main(){
    vector<int> treeNodes = {1,2,3};
    TreeNode* root = CartesianTree(treeNodes);
    inOrderTraversal(root);
    return 0;
}
/*
Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

    Half nodes are nodes which have only one child.
    Leaves should not be touched as they have both children as NULL.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *generateTree(vector<int> nodes)
{
    if (nodes.size() == 0 || nodes[0] == -1)
        return NULL;
    TreeNode *root = new struct TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        int n = q.size();
        for (int idx = 0; idx < n; idx++)
        {
            TreeNode *t = q.front();
            q.pop();
            if (nodes[i] != -1)
            {
                t->left = new struct TreeNode(nodes[i]);
                q.push(t->left);
            }
            else
                t->left = NULL;
            i++;
            if (nodes[i] != -1)
            {
                t->right = new struct TreeNode(nodes[i]);
                q.push(t->right);
            }
            else
                t->right = NULL;
            i++;
        }
    }
    return root;
}

TreeNode *removeHalfNodes(TreeNode *A)
{
    if(A==NULL)return A;
    // If the root itself has only one child then return that child only
    if(A->left && !A->right)return removeHalfNodes(A->left);
    if(A->right && !A->left)return removeHalfNodes(A->right);
    // Doing a level order traversal to remove all the half nodes
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->left && ((t->left->left && !t->left->right) || (!t->left->left && t->left->right)))
            {
                while(t->left)
                // Removing the nodes which have only left child and no right child
                // using while instead of if because may be the child of child has to be removed too
                {
                    TreeNode *temp;
                    if (t->left->left)
                        temp = t->left->left;
                    else
                        temp = t->left->right;
                    t->left = temp;
                }
            }
            while(t->right && ((t->right->right && !t->right->left) || (t->right->left && !t->right->right)))
                {
                    // Removing the nodes which have only right child and no left child
                    // using while instead of if because may be the child of child has to be removed too
                    TreeNode *temp;
                    if (t->right->left)
                        temp = t->right->left;
                    else
                        temp = t->right->right;
                    t->right = temp;
                }
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
    }
    return A;
}
void inOrder(TreeNode *A)
{
    if (A == NULL)
        return;
    inOrder(A->left);
    cout << A->val << " ";
    inOrder(A->right);
}
int main()
{
    //vector<int> treeNodes = {1,2,3,-1,-1,4,-1,-1,5,-1,-1};
    vector<int> treeNodes = {1,2,-1,3,-1,-1,-1};
    TreeNode *root = generateTree(treeNodes);
    root = removeHalfNodes(root);
    inOrder(root);
    return 0;
}
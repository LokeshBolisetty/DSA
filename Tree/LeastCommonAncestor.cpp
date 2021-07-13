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

TreeNode *LCA(TreeNode *root, int val1, int val2)
{
    if (!root)
        return NULL;
    if (root->val == val1 || root->val == val2) //If the root is equal to one of the targets
        //then root is the answer. (According to the question 
        //if one of the node is a part of subtree rooted at another, the parent is the answer)
        return root; //So return the current node

    TreeNode *L = LCA(root->left, val1, val2); //Check if either of the targets are present in left subtree
    TreeNode *R = LCA(root->right, val1, val2); //Check if either of the targets are present in right subtree
    if (L && R)
        return root;  // If val1, val2 are on both sides, i.e they are on opposite side of root, then root is the answer
    return L ? L : R; //If one is NULL, that means both the targets are on same side of the root. So return LCA(that subtree, val1,val2)
    //which is L?L:R
}

//Function to check if given value is present in that tree or not
bool find(TreeNode *root, int val1)
{
    if (!root)
        return false;
    if (root->val == val1)
        return true;
    return (find(root->left, val1) || find(root->right, val1));
}


int lca(TreeNode *root, int val1, int val2)
{
    //If either of the values of are not there in the tree at all, return -1
    //The working of this function assumes that the values are already present in the tree
    //So we need to ensure that they are there already. So we are running this explicitly to check if those values are there.
    if (!find(root, val1) || !find(root, val2))
        return -1;
    TreeNode *ans = LCA(root, val1, val2);
    if (!ans)
        return -1;
    return ans->val;
}
int main()
{
    vector<int> treeNodes = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = generateTree(treeNodes);
    return 0;
}
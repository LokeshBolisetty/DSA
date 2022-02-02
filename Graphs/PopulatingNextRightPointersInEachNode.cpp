/**
 * @file PopulatingNextRightPointersInEachNode.cpp
 * @author your name (lokeshbolisetty.github.io)
 * @brief You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
 * @version 0.1
 * @date 2022-02-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief Class used to create Node objects for a complete binary tree with next pointers
 * @param val Value of the node
 * @param right Pointer to the right child
 * @param left Pointer to the left child
 * @param next Pointer to the next right child
 * 
 */
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/**
 * @brief Assigns the next pointer in each node to the next right node in the graph. If there is no node on the right, NULL will be assigned. 
 * 
 * @param root Root of the complete binary tree
 * @return Node* Root the complete binary tree after assigning the next pointers. 
 */
Node *connect(Node *root)
{
    if (root == NULL)
        return root;
    queue<Node *> q;
    q.push(root);
    //root->next = NULL;
    //No need of visited array because this is a tree
    while (!q.empty())
    {
        Node *temp = q.front();
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *o = q.front();
            q.pop();
            o->next = i == n - 1 ? NULL : q.front();
            if (o->left)
                q.push(o->left);
            if (o->right)
                q.push(o->right);
        }
    }
    return root;
}
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int main()
{

    return 0;
}
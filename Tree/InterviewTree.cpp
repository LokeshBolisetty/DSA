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
int main(){
    vector<int> treeNodes = {8,3,10,1,6,-1,14,-1,-1,4,7,13,-1,-1,-1,-1,-1,-1,-1};
    TreeNode* root = generateTree(treeNodes);
    return 0;
}
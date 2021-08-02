#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int d) {
        val = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
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

int MaxSumInBinaryTree(TreeNode* A,unordered_map<TreeNode*,int> mp, int &res){
    if(A==NULL)return 0;
    if(mp.find(A)!=mp.end())return mp[A];
    int ans = 0;
    ans = A->val;
    int right = MaxSumInBinaryTree(A->right,mp,res);
    int left = MaxSumInBinaryTree(A->left,mp,res);
    ans = max(max(left,right)+A->val,A->val);
    int max_top = max(ans,A->val+right+left);
    res = max(res,max_top);
    mp[A] = ans;
    return ans;
}
int solve(TreeNode* A){
    int res = -1;
    unordered_map<TreeNode*, int> mp;
    MaxSumInBinaryTree(A,mp,res);
    return res;
}
int main(){
    vector<int> Nodes = {10,2,10,20,1,-1,-25,-1,-1,-1,-1,3,4,-1,-1,-1,-1};
    //vector<int> Nodes = {1,2,3,-1,-1,-1,-1};
    TreeNode* root = generateTree(Nodes);
    cout<<solve(root)<<endl;
    return 0;
}
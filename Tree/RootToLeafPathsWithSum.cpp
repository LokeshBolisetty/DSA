//Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.
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

void Paths(TreeNode* A,int req,int sum,vector<int> &v,vector<vector<int>> &ans){
    sum+=A->val;
    v.push_back(A->val);
    //Should not be there because the input can contain -ve numbers
    // if(sum>req){
    //     v.pop_back();
    //     return; 
    // }
    if(sum==req && !A->left && !A->right)ans.push_back(v);
    if(A->left)Paths(A->left,req,sum,v,ans);
    if(A->right)Paths(A->right,req,sum,v,ans);
    v.pop_back();
}

vector<vector<int>> PathsWithGivenSum(TreeNode* A,int B){
    vector<vector<int>> ans;
    vector<int> v;
    Paths(A,B,0,v,ans);
    return ans;
}

int main(){
    vector<int> treeNodes = {1000,2000,-1,};
    //vector<int> treeNodes = {1,2,3,-1,-1,-1,-1};
    TreeNode* root = generateTree(treeNodes);
    vector<vector<int>> ans = PathsWithGivenSum(root,22);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<vector<int>> levelOrder(TreeNode* A){
    queue<TreeNode*> q;
    q.push(A);
    vector<vector<int>> ans;
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){

    return 0;
}
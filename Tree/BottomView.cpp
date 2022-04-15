//Level order traversal for Binary tree will be given
//If there is no child, -1 will be given. 
//Null's children will not be given

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int data):data(data){}
};

TreeNode* buildTree(vector<int> input){
    queue<TreeNode*>  q;
    if(input.size()==0)return NULL;
    TreeNode* root = new TreeNode(input[0]);
    q.push(root);
    int idx = 1;
    while(!q.empty() && idx<input.size()){
        TreeNode* temp = q.front();
        temp->left = input[idx] == -1 ? NULL : new TreeNode(input[idx]);
        if(temp->left)q.push(temp->left);
        idx++;
        temp->right = input[idx] == -1? NULL : new TreeNode(input[idx]);
        if(temp->right)q.push(temp->right);
        idx++;
        q.pop();
    }
    return root;
}

void inorder(TreeNode* root){
    if(root->left)inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)inorder(root->right);
}

vector <int> bottomView(TreeNode *root) {
    // Your Code Here
    map<int,int> m;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode* top = q.front().first;
        int idx = q.front().second;
        m[idx] = top->data;
        if(top->left) q.push({top->left, idx-1});
        if(top->right)q.push({top->right,idx+1});
        q.pop();
    }
    vector<int> answer;
    for(auto it=m.begin();it!=m.end();it++){
        answer.push_back(it->second);
    }
    return answer;
}

int main(){
    vector<int> input = {20,8,22,5,3,-1,25,-1,-1,10,14,-1,-1};
    TreeNode* root = buildTree(input);
    vector<int> v = bottomView(root);
    for(int i =0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
//Level order traversal for Binary tree will be given
//If there is no child, -1 will be given. 
//Null's children will not be given

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
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

vector <int> topView(TreeNode *root) {
    // Your Code Here
    map<int,int> m;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode* top = q.front().first;
        int idx = q.front().second;
        if(m.find(idx)==m.end())m[idx] = top->data;
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

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> answer(3);
    if(!root)return answer;
	stack<pair<TreeNode*,int>> s;
	s.push({root,1});
	while(!s.empty()){
		pair<TreeNode*,int> top = s.top();
		s.pop();
		if(top.second==1){
			//Pre order
			answer[1].push_back(top.first->data);
			s.push({top.first,2}); //Sending to inorder
			if(top.first->left)s.push({top.first->left,1});
		}else if(top.second==2){
			answer[0].push_back(top.first->data);
			s.push({top.first,3});
			if(top.first->right)s.push({top.first->right,1});
		}else{
			answer[2].push_back(top.first->data);
		}
	}
	return answer;
}

int main(){
    vector<int> input = {20,8,22,5,3,-1,25,-1,-1,10,14,-1,-1};
    TreeNode* root = buildTree(input);
    vector<vector<int>> v = getTreeTraversal(root);
    for(int i =0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
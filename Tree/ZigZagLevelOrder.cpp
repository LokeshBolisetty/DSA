#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) {
        val = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* IPreTree(int pre[],int in[],int left,int right){
    static int preindex = 0;
    if(left>right) return NULL;
    TreeNode* newNode = new TreeNode(pre[preindex]);
    preindex++;
    if(left == right){
        return newNode;
    }
    int inIndex = m[newNode->val];
    newNode->left = IPreTree(pre,in,left,inIndex-1);
    newNode->right = IPreTree(pre,in,inIndex+1,right);
    return newNode;
}

void printLevelorder(TreeNode* Treenode){
    deque<TreeNode*> s;
    s.push_back(Treenode);
    while(!s.empty()){
        TreeNode* n = s.front();
        if(n->left)
        s.push_back(n->left);
        if(n->right)
        s.push_back(n->right);
        cout<<s.front()->val<<" ";
        s.pop_front();
    }
    cout<<"\n";
}

vector<vector<int>> ZigZagLevelOrder(TreeNode* A){
    queue<TreeNode*> q;
    q.push(A);
    int i=0;
    vector<vector<int>> ans;
    ans.push_back({A->val});
    while(!q.empty()){
        int n = q.size();
        vector<int> v;
        while(n--){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                if(i&1)v.push_back(temp->left->val);
                else v.insert(v.begin(),temp->left->val);
                q.push(temp->left);
            }
            if(temp->right){
                if(i&1)v.push_back(temp->right->val);
                else v.insert(v.begin(),temp->right->val);
                q.push(temp->right);
            }
        }
        i++;
        if(v.size()!=0)ans.push_back(v);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int pre[n],in[n];
    //Take inorder inpupt
    for(int i =0;i<n;i++){
        cin>>in[i];
        m.insert({in[i],i});
        cin.ignore();
    }
    //Take preorder input
    for(int i =0;i<n;i++){
        cin>>pre[i];
        cin.ignore();
    }

    TreeNode* root = IPreTree(pre,in,0,n-1);
    vector<vector<int>> v = ZigZagLevelOrder(root);
    for(auto x:v){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
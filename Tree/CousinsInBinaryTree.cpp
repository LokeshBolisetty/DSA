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
vector<int> printCousins(TreeNode* A,int B){
    if(A->val==B)return {};
    queue<TreeNode*> q;
    bool found = false;
    q.push(A);
    while(!q.empty()){
        int n = q.size();
        vector<int> v;
        while(n--){
            TreeNode* temp = q.front();
            q.pop();
            if((temp->right && temp->right->val==B) || (temp->left && temp->left->val==B)){
                found = true;
            }else{
                if(temp->right){
                    v.push_back(temp->right->val);
                    q.push(temp->right);
                }
                if(temp->left){
                    v.push_back(temp->left->val);
                    q.push(temp->left);
                }
            }
        }
        if(found)return v;
    }
    return {};
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
    vector<int> v = printCousins(root,10);
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    return 0;
}
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
TreeNode* PopulateNextRight(TreeNode* A){
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n = q.size();
        while(n--){
            TreeNode* t = q.front();
            q.pop();
            if(n>0){
                t->next = q.front();
            }
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
    }
    return A;
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
    PopulateNextRight(root);
    cout<<"R"<<endl;
    return 0;
}
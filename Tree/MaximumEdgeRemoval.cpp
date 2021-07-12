#include<iostream>
#include <vector>
#include <queue>
#include<map>
#include<list>
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

map<int,vector<int>> adj;
vector<int> visited;
int DFS(int A,int &res){
    int currentNodes = 0;
    visited[A] = 1;
    for(auto x:adj[A]){
        if(!visited[x]){
            int nextNodes = DFS(x,res);
            if((nextNodes&1)==0)
                res++;
            else currentNodes+=nextNodes;
        }
    }
    return currentNodes+1;
}
int removeEdges(int A,vector<vector<int>> &B){
    visited.clear();
    adj.clear();
    visited.resize(A+1,0);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    int res = 0;
    DFS(1,res);
    return res;
}

int main(){
    vector<vector<int>> B = {{1,2},
                             {1,3},
                             {1,4},
                             {3,5},
                             {4,6}};
    int A =  6;
    cout<<removeEdges(A,B)<<endl;
    return 0;
}
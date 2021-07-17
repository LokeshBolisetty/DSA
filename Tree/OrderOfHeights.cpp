#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

/**
 * Nodes that can be used to make a tree
 * @param left Pointer to the left subtree
 * @param right Pointer to the right subtree
 * @param val Value of the Node
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * This function generates a tree with given nodes. 
 * @param nodes Vector with values to be placed in the nodes of the tree being generated. 
 * Nodes should be formatted as - level order traversed tree with -1 representing NULL. Children of NULL need not be represented. 
 * */
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

vector<int> OrderOfHeights(vector<int> heights,vector<int> pos){
    vector<pair<int,int>> pairWise;
    int n = heights.size();
    for(int i =0;i<n;i++){
        pairWise.push_back({heights[i],pos[i]});
    }
    sort(pairWise.begin(),pairWise.end());
    vector<int> ans(n,-1);
    for(int i =0;i<n;i++){
        int count = pairWise[i].second;
        for(int j=0;j<n;j++){
            if(count==0 && ans[j]==-1){
                ans[j]=pairWise[i].first;
                break;
            }
            else if(ans[j]==-1 || ans[j]>=pairWise[i].first)count--;
        }
    }
    return ans;
}

int main(){
    vector<int> heights = {3,4,6,8};
    vector<int> pos = {0,2,1,0};
    vector<int> ans = OrderOfHeights(heights,pos);
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
    return 0;
}
#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include<unordered_map> +
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
int search(TreeNode* A,int B){
    //We basically do inorder traversal from top and bottom
    //Its similar to searching for A+B using two pointers
    stack<TreeNode*> s1,s2;
    TreeNode* temp1=A,*temp2=A;
    while(temp1!=NULL){
        //Inorder traversal from smallest number to largest number
        s1.push(temp1);
        temp1 = temp1->left;
    }
    while(temp2!=NULL){
        //Inorder traversal from largest number to smallest number
        s2.push(temp2);
        temp2 = temp2->right;
    }
    temp1 = s1.top();
    temp2 = s2.top();
    while(temp1 && temp2 && temp1->val < temp2->val ){
        if(temp1->val+temp2->val==B)return 1;
        else if(temp1->val+temp2->val>B){
            //If A+B>required, decrease B
            //Decreasing is done here by finding the inorder predecessor
            s2.pop();
            temp2 = temp2->left;
            while(temp2){
                s2.push(temp2);
                temp2 = temp2->right;
            }
            temp2 = s2.top();
        }else{
            //If A+B<B, increase A
            //Increasing is done here by finding the inorder successor
            s1.pop();
            temp1 = temp1->right;
            while(temp1){
                s1.push(temp1);
                temp1 = temp1->left;
            }
            temp1 = s1.top();
        }
    }
    return 0;
}


//Different and simpler method
unordered_map<int, vector<TreeNode*>> m;
void populate(TreeNode* root){
    if(root->left)populate(root->left);
    m[root->val].push_back(root);
    if(root->right)populate(root->right);
}

int twoSum(TreeNode* root, int sum){
    populate(root);
    for(auto it=m.begin();it!=m.end();it++){
        //cout<<sum-it->first<<"\t";
        if(m.find(sum-it->first)!=m.end() && m[sum-it->first]!=it->second) return 1;
        if(2*(it->first) == sum && it->second.size()>1)return 1;
    }
    return 0;
}



int main(){
    vector<int> treeNodes = {10,9,20,-1,-1,-1,-1};
    TreeNode* root = generateTree(treeNodes);
    cout<<search(root,19)<<endl;
    return 0;
}
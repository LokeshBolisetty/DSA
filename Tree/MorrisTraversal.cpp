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

void MorrisTraversal(TreeNode* root){
    //This works by finding out the inorder successor of every element and using them to go to the next node
    TreeNode* current = root;
    while(current!=NULL){
        if(current->left==NULL){ //If you dont find any element smaller than current,
            cout<<current->val<<" "; //You are at a position where you can print the element as it is the smallest elemnt 
            current = current->right; //in the elements that are remaining. 
        }else{
            TreeNode* prev = current->left; //If the left is not empty, there are elements smaller than this
            //But before going there, we shall find out the inorder predecessor to this element

            //Finding the inorder predecessor of current

            while(prev->right!=NULL && prev->right!=current){
                //If prev->right==NULL it means you are at the maximum element on the left subtree of current
                //If prev->right ==current it means that this element is the greatest element smaller than the current element.
                prev = prev->right; 
            }
            if(prev->right==NULL){
                //So if you are the maximum element on the left subtree of current, 
                //it means that you are the inorder predecessor of current
                //Assign current as the right pointer of the inorder successor
                prev->right = current;
                current = current->left; //And like mentioned in line 48 lets go to further left and find out about the other elements
            }
            else{
                //If you are the greatest element smaller than current, it means you can safely print it now. 
                //That is because you are going to as left as possible and printing the smallest elements on line 44. 
                //After they are done the next smallest element will be the element that has some left pointers but all of which are already printed.
                prev->right = NULL;
                cout<<current->val<<" ";
                current = current->right;
            }
        }
    }
    cout<<endl;
}

int main(){
    vector<int> treeNodes = {8,3,10,1,6,-1,14,-1,-1,4,7,13,-1,-1,-1,-1,-1,-1,-1};
    TreeNode* root = generateTree(treeNodes);
    MorrisTraversal(root);
    return 0;
}
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


int Sum(TreeNode* A,int &sum,int &ans){
    sum+=A->val;
    sum%=1003;
    if(!A->left && !A->right){
        //cout<<sum%1003<<endl;
        ans+=sum%1003;
        ans%=1003;
    }else sum*=10;
    sum%=1003;
    int s = sum;
    if(A->left)Sum(A->left,sum,ans);
    sum = s;
    if(A->right)Sum(A->right,sum,ans);
    return 0;
}
int SumRootToLeaf(TreeNode* A){
    int ans = 0,sum=0;
    Sum(A,sum,ans);
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
    cout<<SumRootToLeaf(root)<<endl;
    return 0;
}
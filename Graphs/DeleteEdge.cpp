/*
Given a undirected tree with N nodes labeled  from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.

Return this maximum possible product modulo 109 + 7.

NOTE:

    The tree is rooted at node labeled with 1.
*/
#include<iostream>
#include<vector>
using namespace std;
int findOptimalEdge(vector<int> &A,vector<int> adj[],vector<bool> &visited,int root,int sum,long long &ans){
    #define MOD 1000000007

    //Sum of subtree rooted at root
    long long sumInSubTree = A[root];
    visited[root] = true;

    for(int i=0;i<adj[root].size();i++){
        if(!visited[adj[root][i]]){
            findOptimalEdge(A,adj,visited,adj[root][i],sum,ans);
            //Here we are adding the sum of all subtrees rooted at the root
            sumInSubTree+=A[adj[root][i]];
            sumInSubTree%=MOD;
        }
    }
    //We assign the subtree sum in A[root] itself so that next time while calculating the parent, we can directly add A[adj][i]] to the sum
    A[root] = sumInSubTree;
    //The sum on deleting an edge root and its parent is (sum-(sum of nodes in this subtree))*(sum of nodes in this subtree)
    ans = max(ans,((sum-sumInSubTree)*sumInSubTree)%MOD);
    return ans;
}
int deleteEdge(vector<int> &A,vector<vector<int>> &B){
    int vertices = A.size();
    vector<int> adj[vertices];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }

    long long sum = 0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        sum%=MOD;
    }
    
    int root = 0;
    vector<bool> visited(vertices,0);
    long long ans = 0;
    return findOptimalEdge(A,adj,visited,root,sum,ans);
}
int main(){
    vector<int> A = {11,12};
    vector<vector<int>> B = {{1,2}};
    cout<<deleteEdge(A,B)<<endl;
    return 0;
}
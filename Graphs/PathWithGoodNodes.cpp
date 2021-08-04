/*
Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

    Each edge in the tree is bi-directional.
*/
#include<iostream>
#include<vector>
using namespace std;

/**
 * This uses DFS to find the number of paths having less than req good nodes
 * @param A Vector to check if a node is good. If A[i] if 1 then i+1 is a good node
 * @param adj Adjacency list of the graph with 1 indexing
 * @param count The number of paths with less than req good nodes aka the answer
 * @param root The node from which DFS should start
 * @param req Maximum number of good nodes allowed in a path
 * @param ans The number of good nodes in the current path encountered till now
 * @param visited Vector to check if the node has already been visited or not. 
 * If visited[i]=1 then the node has already been visited
 * @return The number of paths with less than req good nodes. 
 * */
int countPaths(vector<int> &A,vector<int> adj[],int &count,int root,int req,int ans,vector<int> &visited){
    visited[root]=1;
    if(A[root-1]==1)ans++;

    //If the number of neighbours of a node is 1, then its a root node
    if(adj[root].size()==1){
        //If the number of good nodes is less than or equal to req, then this path has to be considered for the answer
        if(ans<=req)count++;

        return count;
    }

    //If the number of good nodes is already greater than required, there is no need of going ahead in the path
    if(ans>req)return count;

    for(int i =0;i<adj[root].size();i++){
        if(!visited[adj[root][i]]){
            countPaths(A,adj,count,adj[root][i],req,ans,visited);
        }
    }
    return count;
}

/**
 * Function to count the number of paths with less than C good nodes
 * @param A Vector to check if a node is good. If A[i] if 1 then i+1 is a good node
 * @param B Vector of all the edges in the graph
 * @param C The number of paths with less than req good nodes aka the answer
 * @return Number of paths with less than C number of good nodes. 
 * */
int pathWithGoodNodes(vector<int> &A,vector<vector<int>> &B,int C){
    //Vector to check if the node has already been visited
    //If visited[i]=1 then i+1th node has already been visited
    vector<int> visited(A.size()+1,0);

    //Converting the given edges into an adjacency list
    vector<int> adj[A.size()+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    int count=0;
    int ans = 0;
    return countPaths(A,adj,count,1,C,ans,visited); 
}
int main(){
    vector<int> A = {1, 1, 1, 0, 1, 0, 1, 0 };
    vector<vector<int>> B = {
                            {8, 2},
                            {6, 3},
                            {5, 2},
                            {3, 1},
                            {4, 2},
                            {7, 2},
                            {2, 1}
                            };
    int C = 2;
    cout<<pathWithGoodNodes(A,B,C)<<endl;
    return 0;
}
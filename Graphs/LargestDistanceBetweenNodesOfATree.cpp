/*
    Given an arbitrary unweighted rooted tree which consists of N nodes.

    The goal of the problem is to find largest distance between two nodes in a tree.

    Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

    The nodes will be numbered 0 through N - 1.

    The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Does DFS while calculating the longest path and remembering the farthest vertex
 * @param adj Adjacency list of the graph with 0 indexing
 * @param root The initial vertex from which DFS should start
 * @param visited Vector to check if the vertex has been visited previously or not. 
 *          If visited[i] is 1 then ith vertex has been visited already
 * @param length The length of the path until now
 * @param far The farthest element so far
 * @param longestPath The number of vertices in longest path encountered till now
 * @return Length of the longest path in the graph from the root
 * */
int dfs(vector<int> adj[],int root,vector<int> &visited,int length,int &far,int &longestPath){
    visited[root]=1;
    length++;
    if(length>longestPath){
        longestPath = length;
        far = root;
    }
    for(int i=0;i<adj[root].size();i++){
        if(visited[adj[root][i]])continue;
        dfs(adj,adj[root][i],visited,length,far,longestPath);
    }
    return longestPath;
}

/**
 * Finds the largest distance between any two nodes of the given tree
 * @param A Vector with parent indices
 *         A[i] contains the index of parent of ith node
 *         Root has -1 as parent in A
 * @return The length of longest path from any vertex to any other vertex in the graph
 * */
int findLargestDistance(vector<int> &A){
    /*
    Approach:
    1) pick any node u
    2) find the node which is farthest from u, call it x (calculate using the same approach as in Solution 1)
    3) find the node which is farthest from x, call it q (calculate using the same approach as in Solution 1)
    The answer will be the length of a path from x to q.
    */
    int n = A.size();
    vector<int> adj[n];
    int root;
    for(int i=0;i<n;i++){
        if(A[i] == -1){
            root = i;;
        }
        else{
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
    }

    //First DFS to find one of the farthest node from the root
    vector<int> visited(A.size(),0);
    int ans = 0;
    int far = root;
    int maxFar = 0;
    dfs(adj,root,visited,0,far,maxFar);

    //DFS from the farthest node
    int newRoot = far;
    far = newRoot;
    maxFar = 0;
    for(int i=0;i<visited.size();i++)visited[i]=0;
    dfs(adj,newRoot,visited,0,far,maxFar);
    //maxFar is the number vertices in the longest path. Since we need the length we return maxFar-1
    return maxFar-1;
}
int main(){
    vector<int> A = {-1,0,0,0,1};
    cout<<findLargestDistance(A)<<endl;
    return 0;
}
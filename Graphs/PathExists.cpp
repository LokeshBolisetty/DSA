/*
Question:
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * @brief This function is to check if there is a valid path from source to destination.
 * 
 * @param n Number of vertices in the graph.
 * @param edges Array of edges in the graph. edge[i] = [u,v] means there is an edge between u and v.
 * @param source Source from which path has to be found
 * @param destination Destination to which path has to be found
 * @return true if path exists and false otherwise.
 * 
 */
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //DFS to find if the path exists
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(source);
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    while(!s.empty()){
        int temp = s.top();
        visited[temp] =true;
        if(temp==destination)return true;
        s.pop();
        for(int i=0;i<adj[temp].size();i++){
            if(!visited[adj[temp][i]]){
                s.push(adj[temp][i]);
            }
        }
    }
    return false;
}
int main(){
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;
    bool res = validPath(n,edges,source,destination);
    cout<<res<<"\n";
    return 0;
}
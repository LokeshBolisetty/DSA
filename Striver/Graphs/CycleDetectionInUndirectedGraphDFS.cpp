/*
Yo have been given an undirected graph with 'N' vertices and 'M' edges. 
The vertices are labelled from 1 to 'N'.
Your task is to find if th egraph contains a cycle or not
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle. 
*/
#include<iostream>
#include<vector>

using namespace std;

bool doDFS(vector<int> adj[], vector<bool> visited, int root, int prev){
    if(visited[root])return true;
    visited[root] = true;
    for(int i=0;i<adj[root].size();i++){
        if(!visited[adj[root][i]]){
            bool hasCycle = doDFS(adj, visited, adj[root][i], root);
            if(hasCycle)return true;
        }else if(prev!=adj[root][i])return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& prerequisites, int vertices, int m)
{
        vector<int> adj[vertices+1];
        for(int i=0;i<m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(vertices+1, false);
        for(int i=1;i<=vertices;i++){
            if(visited[i]==false){
                bool hasCycle = doDFS(adj, visited, i, -1);
                if(hasCycle)return "Yes";
            }
        }
        return "No";
}


int main(){
    //The graph is 1-indexed
    vector<vector<int>> edges = {{1,4},{4,3},{3,1}};
    int vertices = 4;
    cout<<"Does the given graph contain a cycle?\n"<<cycleDetection(edges, vertices, edges.size())<<endl;
    return 0;
}
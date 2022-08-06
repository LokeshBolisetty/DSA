/*
Yo have been given an undirected graph with 'N' vertices and 'M' edges. 
The vertices are labelled from 1 to 'N'.
Your task is to find if th egraph contains a cycle or not
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle. 
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool doBFS(vector<int> adj[], vector<bool> &visited, int root){
    //If the root has already been visited, then it means that we are visiting the root twice which indicates a cycle
    if(visited[root])return true;
    queue<pair<int, int>> q;
    q.push({root,-1});
    visited[root] = true;
    while(!q.empty()){
        pair<int,int> front = q.front();
        int top = front.first;
        q.pop();
        for(int i=0;i<adj[top].size();i++){
            if(visited[adj[top][i]]==false)q.push({adj[top][i], top});
            else if(adj[top][i]!=front.second)return true;
            visited[adj[top][i]] = true;
        }
    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int vertices, int NoOfEdges)
{
        vector<int> adj[vertices+1];
        for(int i=0;i<NoOfEdges;i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> visited(vertices+1, false);
        for(int i=1;i<=vertices;i++){
            if(visited[i]==false){
                bool hasCycle = doBFS(adj, visited, i);
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
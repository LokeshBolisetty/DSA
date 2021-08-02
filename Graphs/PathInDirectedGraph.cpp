#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * This does a BFS traversal and checks if there is a path between first and last vertices
 * @param adj edges in the graph with 1 indexing
 * @param root the starting vertex for BFS
 * @param vertices number of vertices in the graph
 * @return 1 if there is a path from first vertex to last index. 0 otherwise
 * */
int doBFS(vector<int> adj[],int root,int vertices){
    vector<int> ans;
    queue<int> q;
    q.push(root);
    vector<int> visited(vertices+1,0);
    visited[root]=1;
    while(!q.empty()){
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for(int i=0;i<adj[temp].size();i++){
            if(adj[temp][i]==vertices)return 1;
            if(!visited[adj[temp][i]]){
                visited[adj[temp][i]]=1;
                q.push(adj[temp][i]);
            }
        }
    }
    return visited[vertices];
}   

/**
 * Checks if there is a path from 1 to node B
 * @param A edges of the graph with 1 indexing
 * @param B number of vertices in the graph
 * @return 1 if there is a path from first vertex to last vertex. 0 otherwise
 * */
int checkPath(vector<vector<int>> &A,int B){
    vector<int> adj[B+1];
    for(int i=0;i<A.size();i++){
        adj[A[i][0]].push_back(A[i][1]);
    }
    return doBFS(adj,1,B);
}
int main(){
    vector<vector<int>> v=  {{1,2},
                             {2,3},
                             {3,4},
                             {4,5}};
    cout<<checkPath(v,5);
    return 0;
}
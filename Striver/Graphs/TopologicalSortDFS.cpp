#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void doTopologicalSort(vector<int> adj[], vector<int> &visited, int root, stack<int> &s){
    if(visited[root])return;
    visited[root] =true;
    for(int i=0;i<adj[root].size();i++){
        if(!visited[adj[root][i]])doTopologicalSort(adj, visited, adj[root][i], s);
    }
    s.push(root);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> visited(v, false);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i])
            doTopologicalSort(adj, visited, i, s);
    }
    vector<int> answer;
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
}

int main(){
    //The graph is 0-indexed
    int noOfVertices = 4;
    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,2}};
    vector<int> topologicallySortedGraph = topologicalSort(edges, noOfVertices, edges.size());
    for(int value:topologicallySortedGraph)cout<<value<<" ";
    cout<<endl;
    return 0;
}
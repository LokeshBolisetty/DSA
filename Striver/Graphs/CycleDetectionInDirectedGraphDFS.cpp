#include<iostream>
#include<vector>
using namespace std;

bool doDFS(vector<int> adj[], int root, vector<int> &visited,vector<int> &dfsNode){
    visited[root] = true;
    dfsNode[root] = 1;
    for(int i=0;i<adj[root].size();i++){
        if(visited[adj[root][i]] && dfsNode[adj[root][i]]==1){
            return true;
        }
        bool hasCycle = doDFS(adj, adj[root][i], visited, dfsNode);
        if(hasCycle)return true;
    }
    dfsNode[root] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> visited(n+1, false);
    //To keep track of whose neighbors we are looking at. 
    //Check the end of file for more explanation
    vector<int> dfsNode(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            
            bool hasCycle = doDFS(adj, i, visited, dfsNode);
            if(hasCycle){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n = 5;
    //The graph is 1-indexed
    vector<pair<int, int>> edges = {{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    cout<<"Does the graph contain a cycle?\n"<<detectCycleInDirectedGraph(n, edges)<<endl;
    return 0;
}

/*
In this case, 
10
1 2
4 5
5 9
5 10
5 1
5 3
6 7
When you go from 5 to 1, since 1 has already been visited earlier
the program would think that there is a cycle if we don't use the dfsNode array
*/
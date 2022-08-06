#include<vector>
#include<iostream>
using namespace std;

vector<int> doDFS(vector<int> adj[], vector<bool> &visited, vector<int> &answer, int root){
    if(visited[root])return answer;
    visited[root] = true;
    answer.push_back(root);
    for(int i=0;i<adj[root].size();i++){
        if(!visited[adj[root][i]])doDFS(adj, visited, answer, adj[root][i]);
    }
    return answer;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for(vector<int> x:edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    vector<bool> visited(V, false);
    vector<vector<int>> answer;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            vector<int> dummy = {};
            answer.push_back(doDFS(adj, visited, dummy, i));
        }
    }
    return answer;
}

int main(){
    int V = 5, E = 4;
    vector<vector<int>> edges = {{0,2},{0,1},{1,2},{3,4}};
    vector<vector<int>> answer = depthFirstSearch(V, E, edges);
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
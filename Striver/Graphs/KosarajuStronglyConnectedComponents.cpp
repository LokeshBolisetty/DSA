#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(stack<int> &s, vector<int> adj[], int root, vector<int> &visited){
    visited[root] = true;
    for(int x:adj[root]){
        if(!visited[x])dfs(s, adj, x, visited);
    }
    s.push(root);
}
vector<int> revDFS(vector<int> adj[], int root, vector<int> &visited, vector<int> &answer){
    visited[root] = true;
    answer.push_back(root);
    for(auto x:adj[root]){
        if(!visited[x])revDFS(adj, x, visited, answer);
    }
    return answer;
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n], transpose[n];
    for(int i=0;i<edges.size();i++){
        for(int j=0;j<edges[i].size();j++){
            adj[edges[i][0]].push_back(edges[i][1]);
            transpose[edges[i][1]].push_back(edges[i][0]);
        }
    }
    stack<int> s;
    vector<int> visited(n, false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(s,adj, i, visited);
        }
    }
    vector<vector<int>> answer;
    for(int i=0;i<n;i++)visited[i] = false;
    while(!s.empty()){
        int x = s.top();
        s.pop();
        if(!visited[x]){
            vector<int> tempAnswer;
            answer.push_back(revDFS(transpose,x, visited,tempAnswer));
        }
    }
    return answer;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{1,4},{2,3},{3,2},{4,0}};
    vector<vector<int>> answer = stronglyConnectedComponents(n, edges);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
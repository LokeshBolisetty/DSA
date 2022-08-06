#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    vector<int> indegree(v,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    vector<int> visited(v, false);
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int> answer;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        answer.push_back(top);
        for(int i=0;i<adj[top].size();i++){
            indegree[adj[top][i]]--;
            if(indegree[adj[top][i]]==0)q.push(adj[top][i]);
        }
    }
    return answer;
}

int main(){
    //The graph is 0 indexed
    int noOfVertices = 4;
    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,2}};
    vector<int> topologicallySortedGraph = topologicalSort(edges, noOfVertices, edges.size());
    for(int value:topologicallySortedGraph)cout<<value<<" ";
    cout<<endl;
    return 0;
}
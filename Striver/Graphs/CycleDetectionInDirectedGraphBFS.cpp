#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
    vector<int> adj[v+1];
    vector<int> indegree(v+1,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
        indegree[edges[i].second]++;
    }
    queue<int> q;
    for(int i=1;i<=v;i++){
        if(indegree[i]==0)q.push(i);
    }
    int count = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        count++;
        for(int i=0;i<adj[top].size();i++){
            indegree[adj[top][i]]--;
            if(indegree[adj[top][i]]==0)q.push(adj[top][i]);
        }
    }
    if(count==v)return 0;
    return 1;
}

int main(){
    int n = 5;
    //The graph is 1-indexed
    //vector<pair<int, int>> edges = {{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    vector<pair<int,int>>edges = {{1,2},{2,3},{3,4},{4,5}};
    cout<<"Does the graph contain a cycle?\n"<<detectCycleInDirectedGraph(n, edges)<<endl;
    return 0;
}

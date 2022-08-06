/*
Given a graph, check whether the graph is bipartite or not. 
Your function should return true if the given graph's vertices can be divided into two independent sets,
 ‘U’ and ‘V’ such that every edge (‘u’, ‘v’) either connects a vertex from ‘U’ to ‘V’ or a vertex from ‘V’ to ‘U’.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/**
 * @brief Checks if the given graph is bipartite or not using BFS
 * 
 * @param edges Adjacency matrix. If edges[i][j] == 1, it means that there is a bidirectional edge between i and j.
 * @return true If the graph is bipartite
 * @return false If the graph is not bipartite
 */
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int numOfVertices = edges.size();
	vector<int> adj[numOfVertices];
    for(int i=0;i<numOfVertices;i++){
        for(int j=0;j<edges[i].size();j++){
            if(edges[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(numOfVertices, -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int x:adj[top]){
            if(color[x]==color[top])return false;
            if(color[x]==-1)q.push(x);
            color[x] = 1-color[top];
        }
    }
    return true;
}

int main(){
    /*
        You are given a 2D array ‘edges’ which contains 0 and 1, 
        where ‘edges[i][j]’ = 1 denotes a bi-directional edge from ‘i’ to ‘j’.
    */
    vector<vector<int>> edges = {{0,1,0,0},
                                 {0,0,0,1},
                                 {0,0,0,0},
                                 {0,0,0,0}};
    cout<<"Is the graph bipartite?\n"<<isGraphBirpatite(edges)<<endl;
    return 0;
}
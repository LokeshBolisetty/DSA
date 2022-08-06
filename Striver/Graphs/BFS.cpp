#include <vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<list>
using namespace std;

/**
 * @brief Performs BFS from the given node
 * 
 * @param ans BFS path traced so far
 * @param adj Adjacency list of the graph
 * @param vis Array to keep track of all the nodes that are already visited
 * @param node Root node from which the BFS starts
 */
void bfs(vector<int> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    
    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        
        //store frontnode in ans
        ans.push_back(frontnode);
        
        //adj node dal do
        for(auto i: adj[frontnode])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    
}

/**
 * @brief Returns a BFS path of the given graph
 * 
 * @param vertex Number of vertices in the graph
 * @param edges List of edges in the graph
 * @return vector<int> 
 */
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> vis;
    
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    for(int i = 0; i < vertex; i++)
           adj[i].sort();
    for(int i=0; i<vertex; i++)
    {
        if(!vis[i])
        {
            bfs(ans, adj, vis, i);
        }
    }
    
    return ans;
}

int main(){
    vector<pair<int, int>> edges = {{0,1},{0,3}, {1,2}, {2,3}};
    vector<int> answer = BFS(4, edges);
    for(auto x:answer)cout<<x<< " ";
    cout<<endl; 
    return 0;
}
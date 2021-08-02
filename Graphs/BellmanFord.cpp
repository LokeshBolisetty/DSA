/*
Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. 
The graph may contain negative weight edges. 
*/
#include<iostream>
#include<vector>
using namespace std;

/**
 * Find the shortest path from root to all the vertices. 
 * If there are negative edge cycles, report them.
 * @param vertices Number of vertices in the graph
 * @param edges Edges of the graph with 0 based indexing
 * @param root The vertex from which all the paths start
 * @return cost of reaching each vertex from root
 * */
vector<int> BellmanFord(int vertices,vector<vector<int>> edges,int root){
    vector<int> cost(vertices,INT16_MAX);
    cost[root] = 0;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<edges.size();j++){
            if(cost[edges[j][0]]==INT16_MAX)continue;
            if(cost[edges[j][1]]>cost[edges[j][0]]+edges[j][2])
                cost[edges[j][1]] = cost[edges[j][0]]+edges[j][2];
        }
    }
    for(int j=0;j<edges.size();j++){
       for(int j=0;j<edges.size();j++){
            if(cost[edges[j][1]]>cost[edges[j][0]]+edges[j][2])
                return {};
        } 
    }
    return cost;
}
int main(){
    int v,e,start;
    cin>>v>>start>>e;
    vector<vector<int>> adj[v+1];
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
        edges.push_back({b,a,c}); //For undirected graphs
        //Since in an undirected graph, every edge with negative weight counts as a negative cycle,
        //for an undirected graph, if you have a negative edge, you will see the result of that of a negative cycle
        adj[a].push_back({b,c});
        adj[b].push_back({a,c}); //Remove this line incase of directed graph
    } 
    vector<int> path = BellmanFord(v,edges,start);
    for(int i =0;i<path.size();i++){
        cout<<i<<"\t"<<path[i]<<endl;
    }
    return 0;
}
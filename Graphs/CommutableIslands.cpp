/*There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Prims algorithm is used to find minimum spanning tree of a given graph
 * It works only for connected graphs. 
 * For unconnected graphs, only the spanning tree of one component containing starting index will be returned. 
 * @param vertices Number of vertices in the given graph
 * @param edges Vector of edges of the graph with 0 based indexing
 * @param start Startind vertex
 * @return cost of the minimum spanning tree
 * */
int Prims(int vertices, vector<vector<int>> adj[],int start){
    vector<bool> visited(vertices,false);

    vector<int> cost(vertices,INT32_MAX);
    cost[start] = 0;

    //vector<int> path(vertices,-1);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({cost[start],start});

    while(!pq.empty()){

        int currentVertex = pq.top().second;
        pq.pop();

        if(visited[currentVertex])continue;
        visited[currentVertex] = true;

        int noOfNeighbours = adj[currentVertex].size();

        for(int i=0;i<noOfNeighbours;i++){

            int neighbour = adj[currentVertex][i][0];
            int weight = adj[currentVertex][i][1];

            if(!visited[neighbour]){
                if(cost[neighbour]>weight){
                    cost[neighbour] = weight;
                    //path[neighbour] = currentVertex;
                }
                pq.push({cost[neighbour],neighbour});
            }

        }
    }

    int sum = 0;
    for(int i=0;i<cost.size();i++){
        sum+=cost[i];
    }
    return sum;
    //cout<<"Sum is "<<sum<<endl;
    
    //return path;
}

int findMinimumCost(int A,vector<vector<int>> &B){
    //All we need to do is to find the minimum cost of connecting all the islands.
    //So it is enough if we find the cost of the minimum spanning tree
    //We use prims algorithm to find the same
    vector<vector<int>> adj[A];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back({B[i][1]-1,B[i][2]});
        adj[B[i][1]-1].push_back({B[i][0]-1,B[i][2]});
    }
    return Prims(A,adj,0);
}

int main(){
    int A = 4;
    vector<vector<int>> B = {{1,2,1},
                             {2,3,4},
                             {1,4,3},
                             {4,3,2},
                             {1,3,10}};
    cout<<findMinimumCost(A,B)<<endl;
    return 0;
}
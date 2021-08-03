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
 * @return path of the minimum spanning tree
 * */
vector<int> Prims(int vertices, vector<vector<int>> adj[],int start){
    vector<bool> visited(vertices,false);

    vector<int> cost(vertices,INT32_MAX);
    cost[start] = 0;

    vector<int> path(vertices,-1);

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
                    path[neighbour] = currentVertex;
                }
                pq.push({cost[neighbour],neighbour});
            }

        }
    }

    int sum = 0;
    for(int i=0;i<cost.size();i++){
        sum+=cost[i];
    }
    cout<<"Sum is "<<sum<<endl;
    
    return path;
}

int main(){
    int v,e,start;
    cout<<"Enter the number of vertices ";
    cin>>v;
    cout<<"Enter the number of edges ";
    cin>>e;
    cout<<"Enter the starting vertex ";
    cin>>start;
    vector<vector<int>> adj[v+1];
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
        edges.push_back({b,a,c});//Remove this line incase of directed graph

        adj[a].push_back({b,c});
        adj[b].push_back({a,c}); //Remove this line incase of directed graph
    } 
    vector<int> path = Prims(v,adj,start);
    for(int i =0;i<path.size();i++){
        cout<<i<<"\t"<<path[i]<<endl;
    }
    return 0;
}
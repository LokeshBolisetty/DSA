#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IN_MAX 21312313

vector<int> dijkstra(int v,vector<pair<int,int>> adj[],int start){
    //adj has pairs. First value is vertex, second is the edge weight
    vector<bool> visited(v,false);
    vector<int> cost(v,INT_MAX);
    vector<int> path(v,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //first is cost and second is index of the vertex. 
    //cost is set first because we want the least cost element always
    pq.push({0,start});
    cost[start] = 0;
    //visited[0] = true;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int currentVertex = p.second;
        if(visited[currentVertex])continue;
        int currentCost = p.first;
        visited[currentVertex] = true;
        int noOfNeighbours = adj[currentVertex].size();
        for(int i=0;i<noOfNeighbours;i++){
            int neighbour = adj[currentVertex][i].first;
            int edgeWeight = adj[currentVertex][i].second;
            if(!visited[neighbour]){
                if(cost[neighbour]>cost[currentVertex]+edgeWeight){
                    cost[neighbour] = cost[currentVertex]+edgeWeight;
                    pq.push({cost[neighbour],neighbour});
                    path[neighbour] = currentVertex;
                }
            }
        }
    }
    return path;
}

int main(){
    int v,e,start;
    cin>>v>>start>>e;
    vector<pair<int,int>> adj[v+1];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c)); //Remove this line incase of directed graph
    } 
    vector<int> path = dijkstra(v,adj,start);
    for(int i =0;i<v;i++){
        cout<<i<<"\t"<<path[i]<<endl;
    }
    return 0;
}
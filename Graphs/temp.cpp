#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//THIS IS FOR A DIRECTED GRAPH. UNDIREECTED GRAPHS HAVE TO BE TAKEN CARE OF
vector<int> dijkstra(int v,vector<pair<int,int>> adj[],int start){
    vector<bool> known(v+1,false);
    vector<int> cost(v+1,INT_MAX);
    vector<int> path(v+1,-1); 
    priority_queue<pair<int,int>> pq;
    cost[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        if(known[p.second])continue;
        known[p.second] = true;
        int currentCost = -p.first;
        for(int i =0;i<adj[p.second].size();i++){
            int weight = adj[p.second][i].second;
            int neighbour = adj[p.second][i].first;
            if(!known[neighbour]){
                if(cost[neighbour]>currentCost+weight){
                    cost[neighbour] = currentCost+weight;
                    path[neighbour] = p.second;
                    pq.push(make_pair(-cost[neighbour],neighbour));
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
    } 
    vector<int> path = dijkstra(v,adj,start);
    for(int i =0;i<v+1;i++){
        cout<<i<<"\t"<<path[i]<<endl;
    }
    return 0;
}
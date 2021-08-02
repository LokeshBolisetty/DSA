#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//THIS IS FOR A DIRECTED GRAPH. UNDIRECTED GRAPHS HAVE TO BE TAKEN CARE OF.


void BellmanFord(vector<vector<int>> edges,int v,int e,int start){
    vector<int> distance(v+1,INT_MAX);
    distance[start] = 0;
    bool flag = true;
    for(int i = 0;i<v-1;i++){
        int count = 0;
        for(int j = 0;j<e;j++){
            int source = edges[j][0];
            if(distance[source]==INT_MAX)continue;
            int dest = edges[j][1];
            int weight = edges[j][2];
            if(distance[dest]>distance[source]+weight){
                count++;
                distance[dest] = distance[source]+weight;
            }
        }
        if(count == 0){
            flag = false;
            break;
        }
    }
    if(flag){
        for(int j = 0;j<e;j++){
                int source = edges[j][0];
                if(distance[source]==INT_MAX)continue;
                int dest = edges[j][1];
                int weight = edges[j][2];
                if(distance[dest]>distance[source]+weight){
                    printf("Graph consists of a negative cycle :(\n");
                    return;
                }
        }
    }
    for(int i =1;i<v+1;i++){
        cout<<i<<"\t"<<distance[i]<<endl;
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v+1];
    vector<vector<int>> edges;
    for(int i =0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        edges.push_back({a,b,c});
    }
    
    BellmanFord(edges,v,e,1);
    return 0;
}
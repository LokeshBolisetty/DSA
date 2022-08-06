#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    for(int i=0;i<vec.size();i++){
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    vector<int> distance(vertices, 1000);
    distance[source] = 0;
    vector<bool> visited(vertices, false);
    //First is distance, second is the node
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    p.push({0,source}); //Distance from source to source is 0
    while(!p.empty()){
        pair<int,int> top = p.top();
        p.pop();
        int idx = top.second;
        visited[idx] = true;
        for(auto x:adj[idx]){
            int neighbor = x.first;
            int distanceToNeighbor = x.second;
            if(!visited[neighbor]){
                if(distance[neighbor]>distance[idx]+distanceToNeighbor){
                    distance[neighbor] = distance[idx]+distanceToNeighbor;
                    p.push({distance[neighbor], neighbor});
                }
            }
        }
    }
    return distance;
}
 
int main(){
    vector<vector<int>> vec =  {{0 ,1, 7},
                                {0, 2, 1},
                                {0, 3, 2},
                                {1, 2, 3},
                                {1, 3, 5}, 
                                {1, 4, 1},
                                {3, 4, 7}};
    int vertices = 5, edges = 7;
    int source = 0;
    vector<int> distance = dijkstra(vec, vertices, edges, source);
    for(int x:distance)cout<<x<<" ";cout<<endl;
    return 0;
}
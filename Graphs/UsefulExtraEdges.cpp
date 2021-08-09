/*
    Given a graph of A nodes. Also given the weighted edges in the form of array B.

    You are also given starting point C and destination point D.

    Also given are some extra edges in the form of vector E.

    You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.

    All roads are one way ie they go from B[i][0] to B[i][1].
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Find the minimum distance from root to all other vertices
 * @param adj Adjacency list of the graph with 0 indexing
 * @param root The vertex from which minimum distance to all other vertices has to be found
 * @param cost Vector to store the distances to all the vertices
 * */
void dijkstra(vector<pair<int,int>> adj[],int root,vector<int> &cost){
    //Number of vertices in the graph
    int A = cost.size();
    vector<bool> visited(A,false);
    visited[root] = true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,root});
    cost[root]=0;
    while(!q.empty()){
        pair<int,int> temp = q.top();
        int current = temp.second;
        visited[current] = true;
        q.pop();
        for(int i=0;i<adj[current].size();i++){
            int neighbour = adj[current][i].first;
            int weight = adj[current][i].second;
            if(!visited[neighbour]){
                if(cost[neighbour]>cost[current]+weight){
                    cost[neighbour]=cost[current]+weight;
                    q.push({cost[neighbour],neighbour});
                }
            }
        }
    }
}

/**
 * Finds the minimum cost of going from C to D using the edges in B and exaclty one edge from E
 * @param A Number of vertices in the graph
 * @param B Edges present in the graph 
 * @param C Starting point of the required path
 * @param D Ending point of the required path
 * @param E Extra edges out of which exactly one can be used to minimise the cost
 * @return The minimum cost of going from C to D using atmost one edge from E, -1 if no path exists
 * */
int findMinimumCost(int A,vector<vector<int>> &B,int C,int D,vector<vector<int>> &E){

    //Given vertices are in 1 indexing. So we need to convert them to 0 based indexing
    C--;D--;

    //Create an adjacency list 
    vector<pair<int,int>> adj[A];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]-1].push_back({B[i][1]-1,B[i][2]});
        adj[B[i][1]-1].push_back({B[i][0]-1,B[i][2]});
    }

    //Normally I did start = dijkstra(adj,A,C) but that was giving TLE.
    //Declaring start first and sending it as a parameter helped
    //We are not initiating it with INT_MAX because that will lead to overflow while calculating distance
    vector<int> start(A,10000000);
    //Finding out the cost of going from C to any vertex
    dijkstra(adj,C,start);

    vector<int> end(A,10000000);
    //Finding out the cost of going from D to any vertex
    dijkstra(adj,D,end);

    //Initiating the answer with cost of going from  to C to D without using any extra edge
    int ans = start[D];
    for(int i=0;i<E.size();i++){
        //The distance of going from C to E[i][0] + D to E[i][1] + the edge weight of E[i][2]
        int distance = start[E[i][0]-1]+end[E[i][1]-1]+E[i][2];
        //The distance of going from C to E[i][1] + D to E[i][2] + the edge weight of E[i][2]
        int distance2 = start[E[i][1]-1]+end[E[i][0]-1]+E[i][2];

        ans = min(ans,min(distance,distance2));
    }

    //If D is unreachable then return -1
    if(ans==10000000)return -1;
    return ans;
}


int main(){
    int A = 3;
    vector<vector<int>> B = {{1,2,1},
                             {2,3,2},};
                             //{3,1,4}};
    int C = 1;
    int D = 3;
    vector<vector<int>> E = {{1,3,2}};
    cout<<findMinimumCost(A,B,C,D,E)<<endl;
    return 0;
}
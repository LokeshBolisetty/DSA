/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

/**
 * @brief Finds the minimum time required for signal to reach from k to all the nodes
 * 
 * @param times Time taken by the signal to reach from times[i][0] to times[u][1] is times[i][2]
 * @param n Number of vertices. 1-based indexing
 * @param k Start vertex
 * @return Min time to reach all the vertices
 */
int networkDelayTime(vector<vector<int>> &times,int n,int k){
    vector<int> cost(n+1,INT32_MAX);
    cost[k] = 0;
    vector<bool> visited(n+1,false);
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<times.size();i++){
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    //First element is the cost and second element is index
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({cost[k],k});
    while(!q.empty()){
        int currentVertex = q.top().second;
        q.pop();
        if(visited[currentVertex])continue;
        visited[currentVertex] = true;
        for(int i=0;i<adj[currentVertex].size();i++){
            int neighbour = adj[currentVertex][i].first;
            int weight = adj[currentVertex][i].second;
            if(!visited[neighbour]){
                if(cost[neighbour]>cost[currentVertex] + weight){
                    cost[neighbour] = cost[currentVertex] + weight;
                    q.push({cost[neighbour],neighbour});
                }
            }
        }
    }
    for(int i=0;i<cost.size();i++)cout<<cost[i]<<" ";
    int maxCost = *max_element(cost.begin()+1,cost.end());
    return maxCost==INT32_MAX?-1:maxCost;
}

int someoneOnLeetCode(vector<vector<int>>& times, int n, int k) {
    //He used set instead of priority queue. Set automatically sorts in ascending order and stores the element only once
    vector<vector<pair<int,int>>> graph(n+1);
    int len=times.size();
    for(int i=0;i<len;i++){
        graph[times[i][0]].push_back({times[i][2],times[i][1]});   
    }
    vector<int> dist(n+1,1000);
    dist[k]=0;
    set<pair<int,int>> st;
    st.insert({0,k});
    while(!st.empty()){
        auto top=*st.begin();
        st.erase(st.begin());
        for(auto neighbour:graph[top.second]){
            if(dist[neighbour.second]>neighbour.first+top.first){
                dist[neighbour.second]=neighbour.first+top.first;
                st.insert({dist[neighbour.second],neighbour.second});
            }
        }
        
    }
    int maxi=-1;
    for(int i=1;i<=n;i++){
        if(dist[i]==1000){
            // cout<<-1<<endl;
            // break;
            return -1;
        }
        maxi=max(maxi,dist[i]);
    }
    return maxi;
    
}
int main(){
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    cout<<networkDelayTime(times,n,k)<<endl;
    return 0;
}
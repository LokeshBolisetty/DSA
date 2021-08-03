#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//Follows the algorithm mentioned in https://www.youtube.com/watch?v=AK7BuT5MgU0

/**
 * Utility function to check if there is a cycle in the given directed graph using DFS
 * @param adj The edges in the graph with 1 indexing
 * @param root The initial vertex with which to perform DFS
 * @param flag The vector to store if a vertex has been visited previously, or is being considered now or has not been visited yet
 * @return 1 if there is a  cycle and 0 otherwise
 * */
int cycleCheck(vector<int> adj[],int root,vector<int> &flag){
    flag[root] = 0;
    for(int i =0;i<adj[root].size();i++){
        if(flag[adj[root][i]]==0){
            return 1;
        }
        else if(flag[adj[root][i]]==-1){
            if(cycleCheck(adj,adj[root][i],flag)){
                return 1;
            }
        }
    }
    flag[root] = 1;
    return 0;
}

/**
 * Checks if there is a cycle in the given DIRECTED graph or not
 * @param A Number of vertices in the graph
 * @param edges List of all edges in the graph
 * @return 1 if there is a cycle in the given graph, 0 othewise
 * */
int detectCycle(int A,vector<vector<int>> edges){

    //Converting the given edges into adjacency list
    vector<int> adj[A+1];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> flag(A+1,-1);

    /**
     * The given graph might not be connected. So we need to do DFS on all the components
     * This loop makes sure that all the vertices are checked and not just a single component
     * */
    for(int i=1;i<=A;i++){
        if(flag[i]==-1){
            if(cycleCheck(adj,i,flag)){
                return 1;
            }
        }
    }
    return false;
}
int main(){
    int vertices = 5;
    vector<vector<int>> edges = {{1,2},
                                 {1,3},
                                 {2,3},
                                 {1,4},
                                 {4,3},
                                 {4,5},
                                 {3,5}};
    if(detectCycle(vertices,edges))cout<<"There is a cycle in the given graph"<<endl;
    else cout<<"The given graph does not contain any cycles"<<endl;
    return 0;
}
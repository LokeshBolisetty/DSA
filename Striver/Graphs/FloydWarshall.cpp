#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000000000
int floydWarshall(int numOfVertices, int numOfEdges, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> graph(numOfVertices+1, vector<int>(numOfVertices+1, MAX));
    for(vector<int> edge: edges){
        graph[edge[0]][edge[1]] = edge[2];
    }
    for(int i=0;i<graph.size();i++){
        graph[i][i] = 0;
    }

    //Checking if using k as the intermediate vertex helps for all K
    for(int k =1;k<=numOfVertices;k++){
        for(int i=1;i<=numOfVertices;i++){
            for(int j=1;j<=numOfVertices;j++){
                if(graph[i][k]!=MAX && graph[k][j]!=MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
    return graph[src][dest];
}

int main(){
        int numOfVertices = 4, numOfEdges = 4;
    vector<vector<int>> edges = {{1,2,4},
                                 {1,3,3},
                                 {2,4,7},
                                 {3,4,-2}};
    cout<<"The shortest distance from 1 to 4 is "<<floydWarshall(numOfVertices, numOfEdges, 1, 4, edges)<<endl;
    return 0;
}
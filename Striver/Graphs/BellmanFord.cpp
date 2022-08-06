#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000000000
int bellmonFord(int numOfVertices, int numOfEdges, int src, int dest, vector<vector<int>> &edges) {
    vector<int> distance(numOfVertices+1, MAX);
    distance[src] = 0;
    for(int i=0;i<numOfVertices-1;i++){
        for(int j=0;j<numOfEdges;j++){
            //If there are negative weights, we tend to update the new weight as MAX+(negative weight) which is wrong because logically, when the weight is MAX, it means that the node is not reachable at all. So we ignore the edge is the source of the edge is not reachable. 
            if(distance[edges[j][0]]==MAX)continue;
            if(distance[edges[j][1]]>distance[edges[j][0]]+edges[j][2]){
                distance[edges[j][1]] = distance[edges[j][0]] + edges[j][2];
            }
        }
    }
    return distance[dest];
}

int main(){
    int numOfVertices = 4, numOfEdges = 4;
    vector<vector<int>> edges = {{1,2,4},
                                 {1,3,3},
                                 {2,4,7},
                                 {3,4,-2}};
    cout<<"The shortest distance from 1 to 4 is "<<bellmonFord(numOfVertices, numOfEdges, 1, 4, edges)<<endl;
    return 0;
}
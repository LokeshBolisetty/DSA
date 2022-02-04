/*
Question:
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class UnionFind{
public:
    UnionFind(int size){
        for(int i=0;i<size;i++){
            root.push_back(i);
            rank.push_back(1);
        }
    }
    int find(int x){
        if(root[x]==x)return x;
        return root[x]=find(root[x]);
    }
    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY)return;
        if(rank[rootX]>rank[rootY]){
            root[rootY] = rootX;
        }else if(rank[rootX]<rank[rootY]){
            root[rootX] = rootY;
        }else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
        return;
    }
private:
    vector<int> root;
    vector<int> rank;
};

struct comparator{
    bool operator()(vector<int> const &a,vector<int> const &b){
        return a[2]>b[2];
    }
};

class Edge{
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};
// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

int leetcodePrims(vector<vector<int>>& points) {
    if (points.size() == 0) {
        return 0;
    }
    int sz = points.size();
    priority_queue<Edge> pq;
    vector<bool> visited(sz);
    int result = 0;
    int count = sz - 1;
    // Add all edges from points[0] vertex
    vector<int>& coordinate1 = points[0];
    for (int j = 1; j < sz; j++) {
        // Calculate the distance between two coordinates
        vector<int>& coordinate2 = points[j];
        int cost = abs(coordinate1[0] - coordinate2[0]) +
                    abs(coordinate1[1] - coordinate2[1]);
        Edge edge(0, j, cost);
        pq.push(edge);
    }
    visited[0] = true;

    while (!pq.empty() && count > 0) {
        Edge edge = pq.top();
        pq.pop();
        int point1 = edge.point1;
        int point2 = edge.point2;
        int cost = edge.cost;
        if (!visited[point2]) {
            result += cost;
            visited[point2] = true;
            for (int j = 0; j < sz; j++) {
                if (!visited[j]) {
                    int distance = abs(points[point2][0] - points[j][0]) +
                                    abs(points[point2][1] - points[j][1]);
                    pq.push(Edge(point2, j, distance));
                }
            }
            count--;
        }
    }
    return result;
}


int Prims(int vertices, vector<vector<int>> adj[],int start){
    vector<bool> visited(vertices,false);
    vector<int> cost(vertices,INT32_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    cost[start] = 0;
    pq.push({cost[start],start});
    while(!pq.empty()){

        int currentVertex = pq.top().second;
        pq.pop();

        if(visited[currentVertex])continue;
        else visited[currentVertex] = true;

        for(int i=0;i<adj[currentVertex].size();i++){

            int neighbour = adj[currentVertex][i][0];
            int weight = adj[currentVertex][i][1];
            
            if(!visited[neighbour]){
                if(cost[neighbour]>weight){
                    cost[neighbour] = weight;
                }
                pq.push({cost[neighbour],neighbour});
            }
        }
    }
    int sum= 0;
    for(int i=0;i<cost.size();i++){
        sum+=cost[i];
    }
    return sum;
}

int connectPrims(vector<vector<int>> &points){
    if(points.size()==0)return 0;
    vector<vector<int>> adj[points.size()];
    for(int i=0;i<points.size();i++){
        for(int j =i;j<points.size();j++){
            adj[i].push_back({j,abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])});
            adj[j].push_back({i,abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])});
        }
    }
    return Prims(points.size(),adj,0);
}

int connectKruskal(vector<vector<int>> &points){
    //We will use Kruskal's algorithm to find the minimum spanning three which will give us the cost of connecting all the points
    //Here distance between the points can be considered as the weight of the edge
    if(points.size()==0)return 0;
    //Union find to check cycle formation
    UnionFind u(points.size());
    //Priority queue to sort the edges
    priority_queue<vector<int>,vector<vector<int>>, comparator> pq;

    //Create the edges
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            int cost = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
            //u.unionSet(i,j);
            pq.push({i,j,cost});
        }
    }

    //Number of edges added
    int edges = 0;
    //Cost of the minimum spanning tree
    int cost = 0;
    while(edges<points.size()-1){
        if(u.find(pq.top()[0]) == u.find(pq.top()[1])){
            pq.pop();
            continue;
        }
        u.unionSet(pq.top()[0],pq.top()[1]);
        edges++;
        cost+=pq.top()[2];
        pq.pop();
    }
    return cost;
}

int main(){
    //Co-ordinates of the points
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<connectPrims(points)<<endl;
    return 0;
}

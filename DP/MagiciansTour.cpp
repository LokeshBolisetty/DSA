//A magician has to go from point A to B in a graph. He can reduce the distance from a city to another city to 0 using a spell.
//But he can use the spell only k times. Find out the minimum distance for going from source to destination.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int findMinDistance(vector<pair<int, int>> adj[], int N, int k)
{ // {dist, {node, leftout}} priority_queue<pair<int, pair<int, int>>> pq; pq.push({0, {1, 0}});
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {1, 0}});
    int dist[N + 1][k + 1];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 0)
                dist[i][j] = 0;
            else
                dist[i][j] = INT32_MAX;
        }
    }

    while (!pq.empty())
    {
        // it -> {dist, {node, leftout}}
        cout<<pq.size()<<" ";
        auto it = pq.top();
        pq.pop();

        int node = it.second.first;
        int x = it.second.second;
        int dis = dist[node][x]; // it.first

        // iterate over all adjacent nodes
        for (auto iter : adj[node])
        {
            int y = iter.first;
            int d = iter.second;

            // at first lets do without leaving out any edges
            if (dis + d < dist[y][x])
            {
                dist[y][x] = dis + d;
                // pq is max heap, but i need minimal distance at top
                // so to make sure the max heap is used as
                // min heap, i converted it by having negatives, so
                // that max heap works in opposite
                pq.push({-1 * (dis + d), {y, x}}); // why did i take -1 ?
            }
            // if the max turn off edges have been done,
            // no need to further turn off edges
            if (x == k)
                continue;

            if (dis < dist[y][x + 1])
            {
                dist[y][x + 1] = dis;
                // pq is max heap, but i need minimal distance at top
                // so to make sure the max heap is used as
                // min heap, i converted it by having negatives, so
                // that max heap works in opposite
                pq.push({-1 * (dis), {y, x + 1}}); // why did i take -1 ?
            }
        }
    }
    int mini = INT32_MAX;
    // in reaching N, you can take any dist
    // by turning of 0, 1, 2, 3, 4, 5,... edges

    for (int i = 0; i <= k; i++)
        mini = min(mini, dist[N][i]);
    return mini;
}
int main()
{
    int N;
    vector<pair<int,int>> A[N];
    cin>> N;
    int S,D;
    cin>>S>>D;  
    int k;
    cin>>k;
    int M,R;
    cin>>M>>R;

    for(int i=0;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        A[a].push_back({b,c});
        A[b].push_back({a,c});
    }
    cout<<findMinDistance(A,M,k)<<endl;
    return 0;
}
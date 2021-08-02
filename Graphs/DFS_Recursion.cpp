#include<iostream>
#include<vector>
using namespace std;
void doDFS(vector<int> adj[],int root,vector<int> &visited){
    visited[root] = 1;
    cout<<root<<" ";
    for(int i=0;i<adj[root].size();i++){
        if(visited[adj[root][i]]==0)
            doDFS(adj,adj[root][i],visited);
    }
    return;
}
int main(){
    int n,v;
    cout<<"Enter the number of vertices ";
    cin>>v;
    cout<<"Enter the number of edges ";
    cin>>n;
    vector<int> adj[v];
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    vector<int> visited(v,0);
    doDFS(adj,0,visited);
    return 0;
}
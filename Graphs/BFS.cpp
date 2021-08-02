#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void doBFS(vector<int> adj[],int root,int vertices){
    queue<int> q;
    q.push(root);
    vector<int> visited(vertices,0);
    visited[root]=1;
    while(!q.empty()){
        int temp = q.front();
        cout<< temp<<" ";
        q.pop();
        for(int i=0;i<adj[temp].size();i++){
            if(!visited[adj[temp][i]]){
                visited[adj[temp][i]]=1;
                q.push(adj[temp][i]);
            }
        }
    }
    return;
}   
int main(){
    int n,v;
    cout<<"Enter the number of vertices ";
    cin>>v;
    cout<<endl;
    cout<<"Enter the number of edges ";
    cin>>n;
    cout<<endl;
    vector<int> adj[v];
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    doBFS(adj,0,v);
    return 0;
}
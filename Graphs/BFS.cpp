#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> doBFS(vector<int> adj[],int root,int vertices){
    vector<int> ans;
    queue<int> q;
    q.push(root);
    vector<int> visited(vertices,0);
    visited[root]=1;
    while(!q.empty()){
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for(int i=0;i<adj[temp].size();i++){
            if(!visited[adj[temp][i]]){
                visited[adj[temp][i]]=1;
                q.push(adj[temp][i]);
            }
        }
    }
    return ans;
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
    vector<int> BFS = doBFS(adj,0,v);
    for(auto x:BFS)cout<<x<<" ";
    cout<<endl;
    return 0;
}
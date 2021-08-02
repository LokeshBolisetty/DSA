#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> doDFS(vector<int> adj[],int root,vector<int> &visited){
    stack<int> s;
    vector<int> ans;
    s.push(root);
    visited[root]=1;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        ans.push_back(temp);
        int n = adj[temp].size();
        for(int i =n-1;i>=0;i--){
            if(!visited[adj[temp][i]]){
                visited[adj[temp][i]]=1;
                s.push(adj[temp][i]);
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
    vector<int> visited(v,0);
    vector<int> DFS = doDFS(adj,0,visited);
    for(auto x:DFS)cout<<x<<" ";
    cout<<endl;
    return 0;
}
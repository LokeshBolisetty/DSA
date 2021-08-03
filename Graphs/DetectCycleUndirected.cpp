#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//This is inefficient
int doDFS(vector<int> adj[],int A,int root){
    vector<int> visited(A+1,0);
    stack<int> s;
    s.push(root);
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        if(visited[temp]==1)return 1;
        else visited[temp]= 1;
        int n = adj[temp].size();
        for(int i =n-1;i>=0;i--){
            if(!visited[adj[temp][i]])
                s.push(adj[temp][i]);
        }
    }
    return 0;
}
int solve(int A,vector<vector<int>> &B){
    if(A<3)return 0;
    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    return doDFS(adj,A,1);
}



bool dfsCycle(int i, int p, vector<int>& vis, vector<vector<int>>& adj){
    vis[i] = 1;
    for(auto x:adj[i]){
        if(!vis[x]){ //If the neightbour is not visited upto now, do DFS on it
            if(dfsCycle(x, i, vis, adj)) return true;
        }
        else if(x != p) return true; //If it's already visited, check if the previous node is its parent
        //If we visited this neighbour from a different node otherthan parent, then it means there is an alternate path to this neighbour
        //That implies the existence of a cycle. So return true
    }
    return false;
}
int Editorial(int n, vector<vector<int> > &b) {
    vector<vector<int>> adj(n+1);
    for(int i=0;i<b.size();i++){
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }
    
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        //Graph can be disconnected. So we need to check all the components
        if(!vis[i]){ //If a vertex is not connected, it means that component is not traversed yet
            if(dfsCycle(i, -1, vis, adj)) return 1;
        }
    }
    return 0;
}


int main(){
    int A = 2;
    vector<vector<int>> B = {{1,2}};
    cout<<solve(A,B)<<endl;
    return 0;
}
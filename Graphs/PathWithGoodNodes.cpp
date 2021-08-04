#include<iostream>
#include<vector>
using namespace std;
int countPaths(vector<int> &A,vector<int> adj[],int &count,int root,int req,int ans,vector<int> &visited){
    visited[root]=1;
    if(A[root-1]==1)ans++;
    if(adj[root].size()==1){
        if(ans<=req)count++;
        return count;
    }
    if(ans>req)return count;
    for(int i =0;i<adj[root].size();i++){
        if(!visited[adj[root][i]]){
            countPaths(A,adj,count,adj[root][i],req,ans,visited);
        }
    }
    return count;
}
int pathWithGoodNodes(vector<int> &A,vector<vector<int>> &B,int C){
    vector<int> visited(A.size()+1,0);
    vector<int> adj[A.size()+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    int count=0;
    int ans = 0;
    return countPaths(A,adj,count,1,C,ans,visited); 
}
int main(){
    vector<int> A = {1, 1, 1, 0, 1, 0, 1, 0 };
    vector<vector<int>> B = {
  {8, 2},
  {6, 3},
  {5, 2},
  {3, 1},
  {4, 2},
  {7, 2},
  {2, 1}
};
    int C = 2;
    cout<<pathWithGoodNodes(A,B,C)<<endl;
    return 0;
}
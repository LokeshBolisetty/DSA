/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int minJumps(vector<int> &A){
int n = A.size();
    queue<pair<int,int>> q;
    map<int,vector<int>> m;
    for(int i=0;i<n;i++){
        m[A[i]].push_back(i);
    }
    q.push({0,0});
    vector<bool> visited(n,false);
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        if(top.first==n-1)return top.second;
        visited[top.first] = true;
        for(int i=0;i<m[A[top.first]].size();i++){
            if(!visited[m[A[top.first]][i]])q.push({m[A[top.first]][i],top.second+1});
            visited[m[A[top.first]][i]] = true;
        }
        m[A[top.first]] = {};
        if(top.first+1<n && visited[top.first+1]==false){
            q.push({top.first+1,top.second+1});
            visited[top.first+1] = true;
        }
        if(top.first-1>=0 && visited[top.first-1]==false){
            q.push({top.first-1,top.second+1});
            visited[top.first-1] = true;
        }
    }
    return INT32_MAX;
}

int main(){
    vector<int> A = {100,-23,-23,404,100,23,23,23,3,404};
    cout<<minJumps(A)<<endl;
    return 0;
}
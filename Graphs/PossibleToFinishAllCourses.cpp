/*
There are a total of A courses you have to take, labeled from 1 to A.

Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool cycleCheck(vector<int> adj[],int root,vector<int> &visited){
    //root is now under consideration. So set visited of root to 0
    visited[root] = 0;
    for(int i=0;i<adj[root].size();i++){
        //if you reach a vertex under consideration then it means that you there is a cycle
        if(visited[adj[root][i]]==0)return true;
        //if the vertex is not visited yet, perfom DFS on that also
        else if(visited[adj[root][i]]==-1){
            if(cycleCheck(adj,adj[root][i],visited))return true;
        }
        //if the vertex is visited already, then ignore it
    }
    //root is visited completely. So set visited[root] to 1
    visited[root]=1;
    return false;
}
/**
 * All that we have to do is to is to model this as a directed graph problem
 * you can reach a node only if you finished its previous node
 * Now we check if there are any cycles in this. If there is a cycle, then we cant take any course 
 * out of the cycle. So we will never be able to complete all the courses.
 * If there is no cycle we can finish all the courses 
 * @param A Number of courses in total
 * @param B Courses to be taken inorder to finish courses in C
 * @param C Courses that can be taken after finishing courses in B
 * So you can finish C[i] only if you finish B[i]
 * @return 1 if you can finish all the courses, 0 otherwise
 * */
int checkPossibility(int A,vector<int> &B,vector<int> &C){

    //Create an adjacency list
    vector<int> adj[A];
    for(int i=0;i<B.size();i++){
        //Given vectors use 1 based indexing. 
        adj[B[i]-1].push_back(C[i]-1);
    }
    vector<int> visited(A,-1);
    for(int i=0;i<A;i++){
        if(visited[i]==-1){
            if(cycleCheck(adj,i,visited))return 0;
        }
    }
    return 1;
}

int main(){
    int A = 2;
    vector<int> B = {1,2};
    vector<int> C = {2,1};
    cout<<checkPossibility(A,B,C)<<endl;
    return 0;
}
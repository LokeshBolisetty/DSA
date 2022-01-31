#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void DFS(vector<vector<int>> &graph,int root,vector<vector<int>> &answer,vector<int> &itr){
    int n = graph.size();
    itr.push_back(root);
    if(root==n-1){
        answer.push_back(itr);
        return;
    }
    for(int i = 0;i<graph[root].size();i++){
        DFS(graph,graph[root][i],answer,itr);
        itr.pop_back();
    }
    return;
}
vector<vector<int>> AllPathsFromSourceToTarget(vector<vector<int>> &graph){
    // int vertices = graph.size();
    // stack<int> s;
    // s.push(0);
    // vector<vector<int>> answer;
    // vector<int> iter;
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     int temp = s.top();
    //     iter.push_back(temp);
    //     if(temp==vertices-1)answer.push_back(iter);
    //     s.pop();
    //     iter.pop_back();
    //     for(int a:graph[temp]){
    //         s.push(a);
    //     }
    // }
    // return answer;
    vector<vector<int>> answer;
    vector<int> itr;
    DFS(graph,0,answer,itr);
    return answer;
}
int main(){
    vector<vector<int>> adj = {{1,2},{3},{3},{}};
    vector<vector<int>> answer = AllPathsFromSourceToTarget(adj);
    for(vector<int> x:answer){
        for(int y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
    return 0;
}
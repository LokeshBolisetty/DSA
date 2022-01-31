#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

double DFS(unordered_map<string,vector<pair<string,double>>>& graph,string start,string end,unordered_map<string,bool>& visited){
    if(start == end)return 1.0;
    if(visited[start])return -1.0;
    visited[start] = true;
    for(int i=0;i<graph[start].size();i++){
        double res = DFS(graph,graph[start][i].first,end,visited);
        if(res != -1.0)return res*graph[start][i].second;
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> m;
    // build the graph
    for(int i = 0;i<equations.size();i++){
        m[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
        m[equations[i][1]].push_back(make_pair(equations[i][0],1.0/values[i]));
    }
    vector<double> res;
    for(int i=0;i<queries.size();i++){
        unordered_map<string,bool> visited;
        if(m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end())res.push_back(-1.0);
        else res.push_back(DFS(m,queries[i][0],queries[i][1],visited));
    }
    return res;
}

int main(){
    //equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5,2.5,5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    vector<double> res = calcEquation(equations,values,queries);
    for(auto i:res)cout<<i<<"\t";cout<<"\n";
    return 0;
}
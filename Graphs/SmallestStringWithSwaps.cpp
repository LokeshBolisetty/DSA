#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class UnionFind{
public:
    UnionFind(int size){
        rank.resize(size);
        root.resize(size);
        
        for(int i=0;i<size;i++){
            root[i] = i;
            rank[i] = 1;
        }

    }
    int find(int x){
        if(x==root[x])return x;
        return root[x] = find(root[x]);
    }
    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)return;
        if(rank[rootX]>rank[rootY])root[rootY] = rootX;
        else if(rank[rootX<rank[rootY]])root[rootX] = rootY;
        else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }
    vector<int> root,rank;
};
string SmallestStringWithSwaps(string s, vector<vector<int>> &pairs){
    UnionFind u(s.size());
    for(int i=0;i<pairs.size();i++){
        u.unionSet(pairs[i][0],pairs[i][1]);
    }
    for(int i=0;i<s.size();i++)u.find(i);
    unordered_map<int,priority_queue<char,vector<char>, greater<char>>> m;
    for(int i=0;i<u.root.size();i++){
        m[u.root[i]].push(s[i]);
    }
    for(int i=0;i<s.size();i++){
        s[i] = m[u.root[i]].top();
        m[u.root[i]].pop();
    }
    return s;
}
int main(){
    string s = "abdc";
    vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
    cout<<SmallestStringWithSwaps(s,pairs)<<endl;
    return 0;
}
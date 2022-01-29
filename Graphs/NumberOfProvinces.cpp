#include<iostream>
#include<vector>
#include<set>
using namespace std;
//This follows zero based indexing
class UnionFind {
public:
    UnionFind(int size){
        for(int i=0;i<size;i++){
            root.push_back(i);
            rank.push_back(1);
        }
        count = size;
    }
    int find(int x){
        if(x==root[x]){
            return x;
        }
        else return root[x] = find(root[x]);
    }
    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY)return;
        if(rank[rootX]<rank[rootY]){
            root[rootX] = rootY;
        }else if(rank[rootX]>rank[rootY]){
            root[rootY] = rootX;
        }else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
        count--;
    }
    bool isConnected(int x,int y){
        return find(x)==find(y);
    }
    int getCount(){
        return count;
    }
private:
    vector<int> root;
    vector<int> rank;
    int count;
};

int findNumberOfProvinces(vector<vector<int>> connections){
    UnionFind u(connections.size());
    for(int i=0;i<connections.size();i++){
        for(int j=i;j<connections[i].size();j++){
            if(connections[i][j])u.unionSet(i,j);
        }
    }

    //If getCount function exists
    return u.getCount();

    //If getCount function is not implemented
    /*
    //So that all the nodes store its root in the array. (Some might store their parent)
    for(int i=0;i<connections.size();i++){
        u.find(i);
    }
    set<int> s;
    for(int i=0;i<u.root.size();i++){
        s.insert(u.root[i]);
    }
    return s.size();\
    */
}

int main(){
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    cout<<findNumberOfProvinces(isConnected)<<endl;
    return 0;
}
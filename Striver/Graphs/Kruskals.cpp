#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include<algorithm>
bool compareVector(const vector<int> &v1, const vector<int> &v2){
    return v1[2]<v2[2];
}
class UnionFind{
    private:
        vector<int> rank;
        vector<int> root;
    public:
        UnionFind(int size){
            root.resize(size);
            rank.resize(size);
            for(int i=0;i<size;i++){
                root[i] = i;
                rank[i] = 1;
            }
        }
        int find(int x){
            if(x==root[x])return x;
            return root[x] = find(root[x]);
        }
        bool unionSet(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX!=rootY){
                if(rank[rootX]>rank[rootY]){
                    root[rootY] = rootX;
                }else if(rank[rootX]<rank[rootY]){
                    root[rootX] = rootY;
                }else{
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            }
            return false;
        }
        bool isConnected(int x, int y){
            return find(x)==find(y);
        }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(), graph.end(), compareVector);
    //The given graph is 1-indexed
    UnionFind uf(graph.size()+10);
    int mst = 0;
    for(int i=0;i<graph.size();i++){
        vector<int> top = graph[i];
        if(uf.unionSet(top[1], top[0])){
            mst+=top[2];
        }
    }
    return mst;
}


int main(){
    // int n = 5, m = 6;
    // vector<vector<int>> edges = {{1,2,6},
    //                              {2,3,5},
    //                              {3,4,4},
    //                              {1,4,1},
    //                              {1,3,2},
    //                              {3,5,3}} ;
    int n = 2, m =1;
    vector<vector<int>> edges = {{1,2,1}};
                        
    cout<<kruskalMST(n, m, edges)<<endl;
    return 0;
}
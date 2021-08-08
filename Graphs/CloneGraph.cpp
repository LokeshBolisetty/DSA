#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/*UndirectedGraphNode* cloneGraph(UndirectedGraphNode* A){
    //Not a correct way. Here in all the maps, I mapped only labels to nodes but labels may not be unique. 
    unordered_map<int, vector<int>> neighbours; //m
    unordered_map<int, UndirectedGraphNode*> nodes;//mp
    queue<UndirectedGraphNode*> q;
    q.push(A);
    while(!q.empty()){
        UndirectedGraphNode* temp = q.front();
        q.pop();
        nodes[temp->label] = new UndirectedGraphNode(temp->label);
        for(int i=0;i<temp->neighbors.size();i++){
            if(nodes.find(temp->neighbors[i]->label)!=nodes.end());
            q.push(temp->neighbors[i]);
            neighbours[A->label].push_back(temp->neighbors[i]->label);
        }
    }

    
    // for(auto it = m.begin();it!=m.end();it++){
    //     UndirectedGraphNode* temp = new UndirectedGraphNode(it->first);
    //     mp[it->first] = temp;
    // }

    for(auto it = nodes.begin();it!=nodes.end();it++){
        int currentLabel = it->first;
        //vector<UndirectedGraphNode*> currentNeighbours = m[currentLabel];
        for(int i=0;i<neighbours[currentLabel].size();i++){
            it->second->neighbors.push_back(nodes[neighbours[currentLabel][i]]);
        }
    }
    return nodes[A->label];   
}*/

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* A){
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    q.push(A);
    UndirectedGraphNode* newStart = new UndirectedGraphNode(A->label);
    m[A] = newStart;
    while(!q.empty()){
        UndirectedGraphNode* currentNode = q.front();
        q.pop();
        for(int i=0;i<currentNode->neighbors.size();i++){
            if(m.find(currentNode->neighbors[i])==m.end()){
                UndirectedGraphNode* newNeighbour = new UndirectedGraphNode(currentNode->neighbors[i]->label);
                m[currentNode->neighbors[i]] = newNeighbour;
                //We need to push only if clone of the neighbour hasn't been produced so that we push every node only once
                q.push(currentNode->neighbors[i]);
            }
            m[currentNode]->neighbors.push_back(m[currentNode->neighbors[i]]);
        }
    }
    return newStart;
}

int main(){
    
    return 0;
}
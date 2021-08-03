/*
There are A people numbered 1 to A in a football academy.
The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately, not all people get along, and several refuse to be put on the same team as that of their enemies.

Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.

Return 1 if it possible to make exactly two teams else return 0.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//This is a bipartite check problem

/**
 * This does BFS and checks if the graph is bipartite or not
 * @param adj Adjacency list of the graph with 1 indexing
 * @param root The inital vertex with which BFS should start
 * @param flag Colour/Team of vertices/players
 *              0 - Team1
 *              1 - Team2
 *             -1 - Not alloted yet
 * */
int doBFS(vector<int> adj[],int root,vector<int> &flag){

    queue<int> q;

    //Initialising the queue with given root
    q.push(root);
    //Give a team to the root arbitarily
    flag[root] = 0;
    
    while(!q.empty()){

        int currentVertex = q.front();
        int currentTeam = flag[currentVertex];

        q.pop();

        for(int i=0;i<adj[currentVertex].size();i++){

            int neighbour = adj[currentVertex][i];
            int neighbourTeam =  flag[neighbour];

            //Neighbours are enemies. They should not be in the same team.
            if(neighbourTeam==currentTeam)return 0;

            //If colour of neighbour has not been alloted yet, allot the opposite colour now
            //And push it into the queue
            else if(neighbourTeam==-1){
                flag[neighbour] = 1-currentTeam;
                q.push(neighbour);
            }
        }
    }
    return 1;
}

/**
 * Checks if the given graph is bipartite or not
 * @param A Number of vertices
 * @param B Edges of the given graph with 1 indexing
 * */
int checkPossibilityForDivision(int A,vector<vector<int>> &B){

    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    /*
      Vector to check the team assigned to a player
     -1 means the team hasn't been assigned yet
      0 means team 1
      1 means team 2
    */
    vector<int> flag(A+1,-1);

    //Runnning the check on all the connected components because the given graph may not be connected
    for(int i=1;i<=A;i++){
        if(adj[i].size()>0 && flag[i]==-1)
            if(doBFS(adj,i,flag)==0)
                return 0;
    }
    return 1;
}
int main(){
    int A = 11;
    vector<vector<int>> B = {{8, 7},
                             {8, 6},
                             {8, 2},
                             {4, 9},
                             {11, 10},
                             {5, 10},
                             {1, 10},
                             {3, 7},
                             {3, 6},
                             {11, 7},
                             {5, 7},
                             {1, 6},
                             {3, 2},
                             {8, 9},
                             {4, 10},
                             {5, 6},
                             {4, 7},
                             {4, 6}};
    cout<<checkPossibilityForDivision(A,B)<<endl;
    return 0;
}
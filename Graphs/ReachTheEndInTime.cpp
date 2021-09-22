#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
string reachTheEnd(vector<string> grid,int maxTime){
    //Find if it is possible to go from top left of grid to the bottom right in maxTime steps when # are obstacle
    //If it is possible, return "YES"
    //If it is not possible, return "NO"
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0,make_pair(0,0)));
    while(!q.empty()){
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if(x == row-1 && y == col-1 && time <= maxTime){
            return "YES";
        }
        if(time>maxTime){continue;}
        if(x+1<row && grid[x+1][y]!='#'){
            q.push(make_pair(time+1,make_pair(x+1,y)));
        }
        if(y+1<col && grid[x][y+1]!='#'){
            q.push(make_pair(time+1,make_pair(x,y+1)));
        }
        if(x-1>=0 && grid[x-1][y]!='#'){
            q.push(make_pair(time+1,make_pair(x-1,y)));
        }
        if(y-1>=0 && grid[x][y-1]!='#'){
            q.push(make_pair(time+1,make_pair(x,y-1)));
        }
    }
    return "NO";
}
int main(){
    vector<string> v = {"...","..."};
    int maxTime = 3;
    cout<<reachTheEnd(v,maxTime)<<endl;
    return 0;
}
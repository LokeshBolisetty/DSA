/*
Rishabh takes out his Snakes and Ladders Game, stares the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

RULES:

    The game is played with cubic dice of 6 faces numbered from 1 to A.
    Starting from 1 , land on square 100 with the exact roll of the die. If moving the number rolled would place the player beyond square 100, no move is made.
    If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.
    If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

BOARD DESCRIPTION:

    The board is always 10 x 10 with squares numbered from 1 to 100.
    The board contains N ladders given in a form of 2D matrix A of size N * 2 where (A[i][0], A[i][1]) denotes a ladder that has its base on square A[i][0] and end at square A[i][1].
    The board contains M snakes given in a form of 2D matrix B of size M * 2 where (B[i][0], B[i][1]) denotes a snake that has its mouth on square B[i][0] and tail at square B[i][1].

*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int findMinimumSteps(vector<vector<int>> &ladders,vector<vector<int>> &snakes){
    //Greedy approach doesn't work here. 
    //Say you are on 17, you analyse the next 6 positions and think taking the ladder on 19 is the best option
    //But you might go to the next level and miss out a bigger ladder in the way
    //So we need to check all the possibilites. 
    //So we model this as a graph problem and find the minimum path from 1 to 100
    //The numnber of steps from one cell to another is obv 1 always. So we dont need any weights. So we can use BFS
    //Hence we model this as a problem with directed graph with each cell connecting to the next 6 cells
    //in case there is a snake or ladder, we connect it to the resulting cell

    map<int,int> ladder,snake;
    for(int i=0;i<ladders.size();i++){
        ladder[ladders[i][0]] = ladders[i][1];
    }
    for(int i=0;i<snakes.size();i++){
        snake[snakes[i][0]] = snakes[i][1];
    }

    queue<int> q;
    vector<int> grid(100+1,0);
    q.push(1);
    int steps = INT32_MAX;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=current+1,j=0;i<=100 && j<6;j++,i++){
            if(!grid[i]){
                if(ladder.find(i)!=ladder.end() && !grid[ladder[i]]){
                    q.push(ladder[i]);
                    grid[ladder[i]]=grid[current]+1;
                    if(ladder[i]==100)
                        steps = min(steps,grid[100]);
                }
                /*Least number of steps can happen when you go through a snake
                Example
                    { {3,54},
                      {37,100}
                    };
                    {
                        {56, 33}
                    };
                */
                else if(snake.find(i)!=snake.end() && !grid[snake[i]]){
                    grid[snake[i]]=grid[current]+1;
                    q.push(snake[i]);
                }
                else if(snake.find(i)==snake.end()){
                    grid[i]=grid[current]+1;
                    if(i==100)
                        steps = min(steps,grid[100]);
                    q.push(i);
                }
                
            }
        }
    }
    if(grid[100]==0)return -1;
    return steps;
}
int main(){
    vector<vector<int>> ladders = { {3,90}
                                    };
    vector<vector<int>> snakes = {
  {99, 10},
  {97, 20},
  {98, 30},
  {96, 40},
  {95, 50},
  {94, 60},
  {93, 70}
};
    cout<<findMinimumSteps(ladders,snakes)<<endl;
    return 0;
}
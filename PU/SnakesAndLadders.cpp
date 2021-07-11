#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
#define INT_MAX 2147483647
int counter = 200000000;
void stepCounter(int start,unordered_map<int,int> &ladder,unordered_map<int,int> &snake,int steps){
    if(start==100)counter = min(counter,steps);
    if(steps>100)return;
    for(int i=1;i<=6;i++){
        if(start+i==100)counter = min(counter,steps+1);
        else if(start+i>100)return;
        if(ladder.find(start+i)!=ladder.end())stepCounter(ladder[start+i],ladder,snake,steps+1);
        else if(snake.find(start+i)!=snake.end())continue;
        else stepCounter(start+i,ladder,snake,steps+6);
    }
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        unordered_map<int,int> ladder,snake;
        for(int i=0;i<n;i++){
            int start,end;
            cin>>start>>end;
            ladder[start] = end;
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int start,end;
            cin>>start>>end;
            snake[start] = end;
        }
        stepCounter(1,ladder,snake,0);
        return counter;
    }
    return 0;
}
/*
./"SnakesAndLadders" 
[bolisettylokesh@fedora PU]$ cd "/home/bolisettylokesh/Downloads/CP/PU"
[bolisettylokesh@fedora PU]$ ./"SnakesAndLadders" 
1
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
*/
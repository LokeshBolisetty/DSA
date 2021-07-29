/*
There are N Mice and N holes that are placed in a straight line. Each hole can accomodate only 1 mouse.

The positions of Mice are denoted by array A and the position of holes are denoted by array B.

A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x − 1. Any of these moves consumes 1 minute.

Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int assignMiceToHoles(vector<int> &A,vector<int> &B){
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans = 0;
    for(int i=0;i<A.size();i++){
        ans=max(abs(A[i]-B[i]),ans);
    }
    return ans;
}

int main(){
    vector<int> A = {-4,2,3};
    vector<int> B = {0,-2,4};
    cout<<assignMiceToHoles(A,B)<<endl;
    return 0;
}
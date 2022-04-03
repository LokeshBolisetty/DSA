/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Notice that you can not jump outside of the array at any time.
https://leetcode.com/problems/jump-game-iii/
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool canReach(vector<int>& arr, int start) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(arr.size(),false);
    while(!q.empty()){
        int top = q.front();
        visited[top] = true;
        if(arr[top]==0)return true;
        q.pop();
        if(arr[top]+top<arr.size() && arr[top]+top>=0 && !visited[top+arr[top]]){
            q.push(arr[top]+top);
        }
        if(top-arr[top]>=0  && top - arr[top]<arr.size() && !visited[top-arr[top]]){
            q.push(top-arr[top]);
        }
    }
    return false;
}
int main()
{
    vector<int> A = {4,2,3,0,1,2};
    int start = 5;
    cout<<boolalpha<<canReach(A,start)<<endl;
    return 0;
}
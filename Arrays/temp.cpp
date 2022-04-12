#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPos(vector<int> &A, int start, int end){
    int totalSum;
    if(start!=0)totalSum = A[end]-A[start-1];
    else totalSum = A[end];
    int maxSum = totalSum; 
    int first = start==0?0:A[start-1];
    for(int i=start;i<=end;i++){
        int temp = max(A[i]-first,totalSum-A[i]+first);
        if(temp<maxSum)maxSum = temp;
        else return i;
    }
    return end;
}

int splitArray(vector<int>& nums, int m) {
    vector<int> prefixSum;
    prefixSum.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        prefixSum.push_back(prefixSum[i-1]+nums[i]);
    }
    priority_queue<vector<int>> pq;
    int size = nums.size();
    pq.push({prefixSum[size-1],0,size-1});
    while(pq.size()<m){
        int sum = pq.top()[0];
        int start = pq.top()[1];
        int end = pq.top()[2];
        queue<vector<int>> q;
        bool flag = false;
        while(start==end && !pq.empty()){
            flag = false;
            start = pq.top()[1];
            end = pq.top()[2];
            q.push(pq.top());
            pq.pop();
        }
        //if(pq.empty())return -1;
        if(!flag && !pq.empty())pq.pop();
        
        int pos = findPos(prefixSum,start,end);
        int lastSum;
        if(pos!=0)
        lastSum = prefixSum[end]-prefixSum[pos-1];
        else lastSum = prefixSum[end];
        pq.push({sum-lastSum,start,pos-1});
        pq.push({lastSum,pos,end});
        while(!q.empty()){
            pq.push(q.front());
            q.pop();
        }
    }
    return pq.top()[0];
}


int main(){
    vector<int> v = {0,0,0,0,0,0};
    int m = 4;
    cout<<splitArray(v,m)<<endl;
    return 0;
}
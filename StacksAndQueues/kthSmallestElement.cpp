#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kthsmallest(vector<int> &A, int B) {
    priority_queue<int> pq;
    for(int i =0;i<A.size();i++){
        if(pq.size()<B){
            pq.push(A[i]);
        }else{
            if(pq.top()>=A[i]){
                pq.pop();
                pq.push(A[i]);
            }
        }
    }
    return pq.top();
}
// 1 9 2 5 8 3 
// 1 2 9
int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        arr.push_back(r);
    }
    cout<<kthsmallest(arr,k);
    return 0;
}
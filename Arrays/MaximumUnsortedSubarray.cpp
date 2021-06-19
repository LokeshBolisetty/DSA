#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> MaxUnsortedArray(vector<int> A){
    int n = A.size();
    int minCross,maxCross;
    for(int i =0;i<n-1;i++){
        if(A[i]>A[i+1]){
            minCross = i;
            break;
        }
    }
    if(minCross==n-1)return {-1};
    for(int i =n-1;i>0;i--){
        if(A[i]<A[i-1]){
            maxCross=i;
            break;
        }
    }
    int maxEle = A[minCross],minEle=A[minCross];
    for(int i =minCross+1;i<=maxCross;i++){
        if(maxEle<A[i])maxEle=A[i];
        if(minEle>A[i])minEle=A[i];
    }
    for(int i =0;i<minCross;i++){
        if(A[i]>minEle){
            minCross=i;
            break;
        }
    }
    
    for(int i=n-1;i>=maxCross+1;i--){
        if(A[i]<maxEle){
            maxCross=i;
            break;
        }
    }
    return {minCross,maxCross};
}
int main(){
    vector<int> A = {0,1,15,25,6,7,30,40,50};
    // 0 1 5 6 7 15 25 30 40 50 so 15(2) to 7(5) have to be sorted
    // 0,1,15,min(25),max(6)7,30,40,50
    // i.e minCross is 25 and maxCross is 6 which means 15 to 6 is the candidate for answer right now
    // Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. There is no such element in above example 1. 
    // Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. In the above example 1, e is changed to 8 (index of 35)
    vector<int> p = MaxUnsortedArray(A);
    for(int i =0;i<p.size();i++){
        cout<<p[i]<<" ";
    }cout<<endl;
    return 0;
}
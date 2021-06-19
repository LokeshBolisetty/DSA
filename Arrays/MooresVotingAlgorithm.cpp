#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
A majority element in an array A[] of size n
is an element that appears more than n/2 times 
(and hence there is at most one such element).

This algortihm uses O(1) space and O(n) time
*/

/* This is a two-step process. 
 The first step gives the element that maybe the majority element in the array. 
 If there is a majority element in an array, 
    then this step will definitely return majority element, otherwise, 
    it will return candidate for majority element.
 Check if the element obtained from the above step is majority element. 
 This step is necessary as there might be no majority element.
 */
int MajorityElement(vector<int> A){
    int n = A.size();
    int count=1,candidate = A[0];
    for(int i =0;i<n;i++){
        if(A[i]==candidate)count++;
        else count--;
        if(count==0){
            candidate=A[i];
            count=1;
        }
    }
    //Checking if the candidate we got is actually a majoority element. 
    count=0;
    for(int i =0;i<n;i++){
        if(A[i]==candidate)count++;
    }
    if(count>n/2)return candidate;
    return -1;
}
int main(){
    vector<int> A = {1,3,3,1,2};
    cout<<MajorityElement(A)<<endl;
    return 0;
}
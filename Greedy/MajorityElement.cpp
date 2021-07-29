/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findMajorityElement(vector<int> &A){
    //Gives the answer in O(n) time and O(n) space
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
        m[A[i]]++;
        if(m[A[i]]>A.size()/2)return A[i];
    }
    return -1;
}
int MooresVoting(vector<int> &A){
    //This gives the solution in O(n) time and O(1) space unlike the above method
    /*
        Note:
            Moore's Voting algorithm gives correct majority element if there is a majority element in the given vector
            If there isn't a majority element, then it gives some random element. So we need to check using another O(n) time if it is the majority element of not
            Since this question says that there is a majority element already, we are not checking if the element at maj_idx is the majority element or not
            Otherwise, we should have checked if the element we have is majority element or not
    */
    int count = 0, maj_idx = 0;
    for(int i=0;i<A.size();i++){
        //If the element is same as the proposed majority element increase the count
        if(A[i]==A[maj_idx])count++;
        //If not decrease the count
        else count--;

        //If you reached a point where count=0, it might be possible that majority element is not the one at maj_idx
        //So assign maj_idx to the current element. 
        if(count==0){
            maj_idx = i;
            count=1;
        }
    }
    return A[maj_idx];
}
int main(){
    vector<int> A = {2,2,1,1,1};
    cout<<MooresVoting(A)<<endl;
    return 0;
}
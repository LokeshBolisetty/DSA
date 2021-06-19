/*
Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.

Your algorithm’s runtime complexity must be in the order of O(log n).

Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
*/
#include<iostream>
#include<vector>
using namespace std;
///FFFTTT
int FirstTrue(vector<int> A,int B){
    int low=0,high=A.size()-1;
    int mid = low+(high-low)/2;
    while(low<high){
        mid = low+(high-low)/2;
        if(B<=A[mid])high = mid;
        else low = mid+1;
    }
    return high;
}
int LastTrue(vector<int> A,int B){
    int low = 0,high = A.size()-1;
    int mid;
    while(low<high){
        mid = low+(high-low+1)/2;
        if(B>=A[mid])low = mid;
        else high = mid-1;
    }
    return low;
}
vector<int> Range(vector<int> A,int B){
    ///Find out first False TTTTFFFF target>=A[i] which gives final index
    int end = LastTrue(A,B);
    if(A[end]!=B)return {-1,-1};
    int start = FirstTrue(A,B);
    return {start,end};

}
int main(){
    vector<int> A = {5,7,7,8,8,10,12,15};
    int B = 8;
    vector<int> C = Range(A,B);
    cout<<C[0]<<C[1]<<endl;
    return 0;
}

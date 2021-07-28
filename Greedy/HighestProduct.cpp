/*
Given an array A, of N integers A.

Return the highest product possible by multiplying 3 numbers from the array.

NOTE: Solution will fit in a 32-bit signed integer.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findHighestProduct(vector<int> &A){
    sort(A.begin(),A.end());
    int n = A.size();
    //In examples like [ 0, -1, 3, 100, -70, -50 ] where negative numbers are large we should consider them also
    return max(A[n-1]*A[n-2]*A[n-3],A[n-1]*A[0]*A[1]);
}
int main(){
    vector<int> A = {1,2,3,4};
    //cout<<findHighestProduct(A)<<endl;
    return 0;
}
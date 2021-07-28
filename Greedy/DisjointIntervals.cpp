/*
Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Custom Comparator to sort by the second element of the vector
 * @param A First value to be compared
 * @param B Second value to be compared
 * */
bool custCompare(vector<int> &A,vector<int> &B){
    //Both the codes work

    // if(A[1]>B[1])return 0;
    // if(A[1]<B[1])return 1;
    // if(A[0]>B[0])return 0;
    // return 1;

    return A[1]<B[1];
}

int disjointIntervals(vector<vector<int>> &A){
    /*
        Sort the intervals, with respect to their end points.
        Now, traverse through all the intervals, if we get two overlapping intervals, then greedily choose the interval with lower end point since, choosing it will ensure that intervals further can be accommodated without any overlap.
        Apply the same procedure for all the intervals and print all the intervals which satisfy the above criteria.
    */
    sort(A.begin(),A.end(),custCompare);
    int n = A.size();
    int count = 1;
    int rightLimit = A[0][1];
    for(int i=1;i<n;i++){
        if(rightLimit<A[i][0]){
            count++;
            rightLimit = A[i][1];
        }
    }
    return count;
}

int main(){
    vector<vector<int>> A = {
  {3, 15},
  {8, 13},
  {5, 13},
  {7, 9},
  {5, 14},
  {2, 6},
  {6, 13},
  {2, 4},
  {3, 11}
};
    cout<<disjointIntervals(A)<<endl;
    return 0;
}